----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date: 03.04.2024 13:10:48
-- Design Name:
-- Module Name: contador41 - Behavioral
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

entity contador41 is
    Port ( clk   : in STD_LOGIC;
           ce    : in STD_LOGIC;
           reset : in STD_LOGIC;
           count : out STD_LOGIC_VECTOR (3 downto 0));
end contador41;

architecture Behavioral of contador41 is

    component ffT_reset
      port (clk   : in std_logic;
            ce    : in std_logic;
            reset : in std_logic;
            t     : in std_logic;
            q     : out std_logic);
      end component;

    component ffD_preset
      port (clk   : in std_logic;
            ce    : in std_logic;
            preset : in std_logic;
            d     : in std_logic;
            q     : out std_logic);
    end component;

    component ffD_reset
      port (clk   : in std_logic;
            ce    : in std_logic;
            reset : in std_logic;
            d     : in std_logic;
            q     : out std_logic);
      end component;

      signal qa, qb, qc, qd: std_logic;
      signal ta, tb, tc, td: std_logic;

begin

  unitA : ffT_reset
    port map (clk   => clk,
              ce    => ce,
              reset => reset,
              t     => ta,
              q     => qa);
  unitB : ffD_preset
    port map (clk   => clk,
              ce    => ce,
              preset => reset,
              d     => db,
              q     => qb);
  unitC : ffD_reset
    port map (clk   => clk,
              ce    => ce,
              reset => reset,
              d     => dc,
              q     => qc);
  unitD : ffD_reset
    port map (clk   => clk,
              ce    => ce,
              reset => reset,
              d     => dd,
              q     => qd);

    dd <= (qa and not qd) or (qb and not qd) or (not QA and not QB and QD);
    dc <= (not qc and qd) or (not qa and not qb and qc);
    db <= (qa and qd) or (not qb and qc) or (qb and not qc and not qd);
    ta <= (qa and qd) or (not qa and not qb and not qc and not qd);

    count <= qa & qb & qc & qd;

end Behavioral;
