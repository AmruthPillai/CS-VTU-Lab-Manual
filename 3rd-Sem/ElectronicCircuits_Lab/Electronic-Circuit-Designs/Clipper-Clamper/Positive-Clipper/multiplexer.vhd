library IEEE;
use IEEE.STD_LOGIC_1164.All;

entity multiplexer is
	port (
		I 	: in 	STD_LOGIC_VECTOR(7 downto 0);
		SEL : in 	STD_LOGIC_VECTOR(2 downto 0);
		ZOUT: out   STD_LOGIC;
	);
end multiplexer;

architecture mux is
	begin
		ZOUT <= I(0) when SEL = "000" else
				I(1) when SEL = "001" else
				I(2) when SEL = "010" else
				I(3) when SEL = "011" else
				I(4) when SEL = "100" else
				I(5) when SEL = "101" else
				I(6) when SEL = "110" else
				I(7) when SEL = "111";
end mux;