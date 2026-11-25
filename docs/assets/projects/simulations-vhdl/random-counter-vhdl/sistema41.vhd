----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date: 17.04.2024 12:58:01
-- Design Name:
-- Module Name: sistema - Behavioral
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

entity sistema41 is
    Port ( clk    : in STD_LOGIC;
           ce     : in STD_LOGIC;
           reset  : in STD_LOGIC;
           count  : out STD_LOGIC_VECTOR (3 downto 0);
           -- an_in  : in STD_LOGIC_VECTOR (7 downto 0);
           -- an_out : out STD_LOGIC_VECTOR (7 downto 0);
           led    : out STD_LOGIC_VECTOR (6 downto 0));
end sistema41;

architecture Behavioral of sistema41 is

    component contador41
        port (clk   : in std_logic;
              ce    : in std_logic;
              reset : in std_logic;
              count : out std_logic_vector (3 downto 0));
    end component;

    component dec7seg
        port (bcd : in std_logic_vector (3 downto 0);
              led : out std_logic_vector (6 downto 0));
    end component;

    signal int : std_logic_vector (3 downto 0);

begin

    Ints_contador41 : contador41
    port map (clk   => clk,
              ce    => ce,
              reset => reset,
              count => int);

    Inst_dec7seg : dec7seg
    port map (bcd => int,
              led => led);

    count <= int;

    -- an_out <= an_in;

end Behavioral;
