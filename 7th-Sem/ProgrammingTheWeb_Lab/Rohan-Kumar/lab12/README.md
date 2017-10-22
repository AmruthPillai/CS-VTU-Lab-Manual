#Building a Rail application to accept and display book information

##Create Database and Tables by following the database.sql commands

##Creating lab12 Project
>rails -d mysql lab12

##Change the directory to lab12
>cd lab12

##Creating controller, model and view from database
>ruby script/generate scaffold Book accession_no:integer title:string authors:text edition:float publisher:string

At this point you can start the server and add & view books
##Starting Rails Server
>ruby script/server

Check in browser
<http://localhost:3000/books>

##Creating main (new) controller for searching book
>ruby script/generate controller main

Now edit the files
+ app\controllers\main_controller.rb
+ app\views\main\result.rhtml
+ app\views\main\welcome.rhtml

##Restart the server and check in browser <http://localhost:3000/main/welcome>
