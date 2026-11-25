----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date: 13.03.2024 09:32:42
-- Design Name:
-- Module Name: funciones41_tb - Behavioral
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

entity funciones41_tb is
--  Port ( );
end funciones41_tb;

architecture Behavioral of funciones41_tb is

    component funciones
           Port ( a : in STD_LOGIC;
                  b : in STD_LOGIC;
                  c : in STD_LOGIC;
                  d : in STD_LOGIC;
                  f1 : out STD_LOGIC;
                  f2 : out STD_LOGIC);
    end component;

    signal a  : std_logic := '0';
    signal b  : std_logic := '0';
    signal c  : std_logic := '0';
    signal d  : std_logic := '0';
    signal f1 : std_logic;
    signal f2 : std_logic;

    constant Tb_semiPeriod : time := 10 ns;

    signal TbSimEnded : std_logic := '0';

begin

    dut : funciones
    port map (a => a,
              b => b,
              c => c,
              d => d,
              f1 => f1,
              f2 => f2);

    d <= not d after Tb_semiPeriod   when TbSimEnded /= '1' else '0';
    c <= not c after Tb_semiPeriod*2 when TbSimEnded /= '1' else '0';
    b <= not b after Tb_semiPeriod*4 when TbSimEnded /= '1' else '0';
    a <= not a after Tb_semiPeriod*8 when TbSimEnded /= '1' else '0';

    TbSimEnded <= '1' after 16 * Tb_semiPeriod;
end Behavioral;
