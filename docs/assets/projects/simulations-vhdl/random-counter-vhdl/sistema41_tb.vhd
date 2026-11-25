----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date: 17.04.2024 13:14:36
-- Design Name:
-- Module Name: sistema_tb - Behavioral
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

entity sistema41_tb is
--  Port ( );
end sistema41_tb;

architecture Behavioral of sistema41_tb is

    component sistema41
        port (clk   : in std_logic;
              ce    : in std_logic;
              reset : in std_logic;
              count : out std_logic_vector (3 downto 0);
              led   : out std_logic_vector (6 downto 0));
    end component;

    signal clk   : std_logic := '0';
    signal ce    : std_logic := '0';
    signal reset : std_logic := '0';
    signal count : std_logic_vector (3 downto 0);
    signal led   : std_logic_vector (6 downto 0);

begin

    dut : sistema41
    port map (clk   => clk,
              ce    => ce,
              reset => reset,
              count => count,
              led   => led);

    clk <= not clk after 10 ns;

    stimuli : process
    begin
        reset <= '1';
        wait for 20 ns;
        ce <= '1'; reset <= '0';
        wait for 180 ns;
        reset <= '1';
        wait;
    end process;

end Behavioral;
