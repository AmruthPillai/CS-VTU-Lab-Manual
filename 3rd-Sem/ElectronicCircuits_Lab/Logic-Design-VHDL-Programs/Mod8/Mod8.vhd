library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.all;

entity Mod8 is
  Port(
    RST, CLK, EN  : in    std_logic;
		Q             : inout std_logic_vector(3 downto 0)
  );
end Mod8;  

architecture Counter of Mod8 is
	begin process(CLK, RST)
		begin if RST = '1' then
      Q <= "0000";
		elsif rising_edge(CLK) then
			if EN = '1' then
				Q <= Q + 1;
			end if;
			if Q = "0111" then
				Q <= "0000";
			end if;
		end if;
	end process;
end Counter;