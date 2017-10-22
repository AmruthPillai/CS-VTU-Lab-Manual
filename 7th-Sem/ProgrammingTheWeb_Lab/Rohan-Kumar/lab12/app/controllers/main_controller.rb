class MainController < ApplicationController
	def welcome
		@num_books = Book.count
	end
	def result
		@booktitle = params[:title]
		@bookz = Book.find(:all, :conditions => "title = '#{@booktitle}'")
	end

end
