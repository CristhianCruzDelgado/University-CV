----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date: 22.04.2024 16:39:16
-- Design Name:
-- Module Name: ffD_reset - Behavioral
-- Project Name:
-- Target Devices:
-- Tool Versions:
-- Description:
--
-- Dependencies:
--
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ffT_reset is
    Port ( reset : in STD_LOGIC;
           clk : in STD_LOGIC;
           ce : in STD_LOGIC;
           t : in STD_LOGIC;
           q : out STD_LOGIC);
end ffT_reset;

architecture Behavioral of ffT_reset is

signal q_int : std_logic;

begin

process (clk, reset)
begin

    if reset='1' then
        q_int <= '0';
    elsif (clk'event and clk='1') then
        if ce = '1' then
            if t = '1' then
                q_int <= not q_int;
            end if;
        end if;
    end if;
end process;

q <= q_int;

end Behavioral;
