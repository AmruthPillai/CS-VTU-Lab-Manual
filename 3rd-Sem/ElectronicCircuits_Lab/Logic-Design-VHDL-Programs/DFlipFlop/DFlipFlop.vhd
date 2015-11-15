library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity DFF is
  Port(
    D, CLK  : in    STD_LOGIC;
    Q       : inout STD_LOGIC;
    Qbar    : out   STD_LOGIC
  );
end DFF;

architecture FF of DFF is
  begin process(CLK)
    begin if rising_edge(CLK) then
      Q <= D;
    end if;
  end process;
  Qbar <= not Q;
end FF;