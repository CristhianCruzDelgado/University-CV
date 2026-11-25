----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date: 13.03.2024 09:32:19
-- Design Name:
-- Module Name: funciones41 - Behavioral
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

entity funciones41 is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : in STD_LOGIC;
           d : in STD_LOGIC;
           f1 : out STD_LOGIC;
           f2 : out STD_LOGIC);
end funciones41;

architecture Behavioral of funciones41 is

begin

    f1 <= (not a and not b and not c and d) or (not a and b and c) or (a and not b and c) or (a and not d) or (c and not d);
    f2 <= (a and b and c and d) or (b and c and not d);

end Behavioral;
