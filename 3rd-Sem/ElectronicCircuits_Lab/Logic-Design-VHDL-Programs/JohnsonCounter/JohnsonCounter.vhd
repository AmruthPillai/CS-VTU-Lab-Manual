library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity JohnsonCounter is
  Port(
    CLK, RST, EN  : in    STD_LOGIC;
    Q             : inout STD_LOGIC_VECTOR(3 downto 0)
  );
end JohnsonCounter;

architecture Behaviour of JohnsonCounter is
  begin process(CLK, RST)
    begin if RST = '1' then
      Q <= "0001";
    elsif rising_edge(CLK) then
      if EN = '1' then
        Q <= ( ( not Q(0) ) & ( Q(3 downto 1) ) );
      end if;
    end if;
  end process;
end Behaviour;