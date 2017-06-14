library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_misc.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library UNISIM;
use UNISIM.vcomponents.all;

entity ram is
   generic(memory_type : string := "DEFAULT");
   port(clk               : in std_logic;
        enable            : in std_logic;
        write_byte_enable : in std_logic_vector(3 downto 0);
        address           : in std_logic_vector(31 downto 2);
        data_write        : in std_logic_vector(31 downto 0);
        data_read         : out std_logic_vector(31 downto 0));
end; --entity ram

architecture logic of ram is
   constant ZERO          : std_logic_vector(31 downto 0) := "00000000000000000000000000000000";
begin

   RAMB16_S9_inst0 : RAMB16_S9
   generic map (
INIT_00 => X"9323232337233723232383b723136713832313b78313ef231313379363ef1317",
INIT_01 => X"238323b3b3838303e38303238363836383238323b3b3b38383036f1313231323",
INIT_02 => X"03b76723b7e3938337671383038303830383e38323ef93032333ef938303e383",
INIT_03 => X"ef139393936f93939313b76313931323232323232323136703b7e39383376713",
INIT_04 => X"67138303830383031383e3a3a3139383036313239363e3a313833333ef131393",
INIT_05 => X"63e3931393636f6393139363631367136713e3133363939313636fa313936f23",
INIT_06 => X"1363e393939363636f93936363136f136f13b3e31333673363e3939333b36313",
INIT_07 => X"936767e39333639363e393139363636f931363636f1393671367e39393333363",
INIT_08 => X"93636393ef6333ef1313136f139393139313131323232323232323232323136f",
INIT_09 => X"130383038303830303831383e39313efef1313ef13ef63e393e39313e39313e3",
INIT_0A => X"ef93131363139323231367130383e303b3131313ef13136303ef232393131367",
INIT_0B => X"038323931313832393836fb713936fef1367130383e303b3131313ef13631303",
INIT_0C => X"13ef13ef1393239323238337231367136f239383e39393631313233313939393",
INIT_0D => X"939363ef13ef13ef139313231393232323231383376713032393838383ef13ef",
INIT_0E => X"ef1313239393232323238337231367132303839303838337e31323ef13b39393",
INIT_0F => X"b76f1323139383038303838337e3ef1303ef13ef1313ef239393832393931383",
INIT_10 => X"830383639333b79333ef1393ef33131393ef1313ef2313130323132323231303",
INIT_11 => X"133767133713830383efb7131313331333ef1393ef33131393ef1313ef136713",
INIT_12 => X"9313ef13e303ef13131337e303ef131313efef37232323232323232323232313",
INIT_13 => X"37e303ef13131337e303ef13131337e303ef13131337e303ef13131337931313",
INIT_14 => X"ef13131337b76783331393b7e313ef13efef13e303ef13131337e303ef131313",
INIT_15 => X"13376f9313631393efe3ef63136f1323b71313efe303ef13131337b76fe7e303",
INIT_16 => X"ef1313139337efe303ef131313376f93efe303ef131313376f93efe303ef1313",
INIT_17 => X"e3efe303ef93139393b7efe303ef93139313b7efe303ef131313376f23efe303",
INIT_18 => X"37ef13ef13e31393efe303ef1313139337efe303ef131313376fe3932393b313",
INIT_19 => X"e303ef13131337e36fef13e3ef13ef1303936363ef13ef130393e303ef131313",
INIT_1A => X"2313033363b7139393a3a3a323232313a3139393132313e303ef13131337ef13",
INIT_1B => X"ef131313376f236f236fe3ef139313e39323130333639393b793e3ef1393e393",
INIT_1C => X"1337ef1313e303ef131313376fef136fe313b3ef13e3ef13136393031393e303",
INIT_1D => X"8c8c8c8c8c207874706c6864393531333762666a6e72767a6c286fe303ef1313",
INIT_1E => X"8c948c1c8c688c8c8c8c8c8c8c8c8c8c8c8cf88c8c8c8c8c8c8c8c8c8c8c8c8c",
INIT_1F => X"0a79696175200a3032532d647420520a488c908c8c8c8ce08c8c8c8c8c8c8c8c",
INIT_20 => X"2020740a7820720a746577200a00666d200a00646d200a4f457270200a206220",
INIT_21 => X"0000000000000065610a0065650a20202928670a206d670a740a6520002d2e61",
INIT_22 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_23 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_24 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_25 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_26 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_27 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_28 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_29 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2F => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_30 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_31 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_32 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_33 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_34 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_35 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_36 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_37 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_38 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_39 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3F => X"0000000000000000000000000000000000000000000000000000000000000000")
   port map (
      DO   => data_read(31 downto 24),
      DOP  => open, 
      ADDR => address(12 downto 2),
      CLK  => clk, 
      DI   => data_write(31 downto 24),
      DIP  => ZERO(0 downto 0),
      EN   => enable,
      SSR  => ZERO(0),
      WE   => write_byte_enable(3));

   RAMB16_S9_inst1 : RAMB16_S9
   generic map (
INIT_00 => X"09262e208a2664222c24a70422018001a7a85507201500260501850500000101",
INIT_01 => X"22272487072726276e272720a7f827e42722272487870727262700040a24092a",
INIT_02 => X"a50780a0078cf7270780012a2a2929242420ec2724000525260500052a25f027",
INIT_03 => X"0085050409008a8904091ae88a07072226282a2c2e240180a5078cf727078075",
INIT_04 => X"80012a2a292924240520640f800787c64670070007c0140f8747858500050405",
INIT_05 => X"82e89707950c00e6070706c24e068005800596150784d5f70784f0808707f080",
INIT_06 => X"0582e6978695cc8e000706cafc07f005f04605d2060580050496d5d76586e605",
INIT_07 => X"07808098d50564d78ee6970795cc0a000707c4f6f0050780058096d5d7650766",
INIT_08 => X"040c0e07f0c484f0091485000c090b0b0a0a090422262426282a2c2e202401f0",
INIT_09 => X"012c2b2b2a2a292924240520160754f0f00905f005f00e1a04fe0407f404077a",
INIT_0A => X"f0050605f804072624018001242012c507075414f004040445f0242605060180",
INIT_0B => X"a6a6a8e61517a6a8f6a600070705f0f0058001242012c507075414f004020445",
INIT_0C => X"f5f0d5f0050428f72226270424018005f0a8e6a6d6d616807775a8e776f6d685",
INIT_0D => X"948486f075f055f08404052809f72022242601270780012428e7242027f005f0",
INIT_0E => X"f084052809f7262a2c2e270928018001282924e724202707180400f0050484d4",
INIT_0F => X"07f0012805e7292924242027071af00445f0f5f075d5f028f7042728e7990527",
INIT_10 => X"2424200c87e5079465f00504f064051417f00504f0a87705a7a86722242601a7",
INIT_11 => X"01e500010305242420f005560516669665f00504f064051417f00504f0058001",
INIT_12 => X"0c0af0051a45f0040405141a45f0040405f0f014222426282a2c2e2022242605",
INIT_13 => X"141a45f0040405141a45f0040405141a45f0040405141a45f0040405140a0b09",
INIT_14 => X"f00404051404802785158717e005f004f0f0051a45f0040405141a45f0040405",
INIT_15 => X"0514f0840a8e0477f00af00004008480d90a04f01a45f00404051404f0801a45",
INIT_16 => X"f00405040414f01a45f004040514f004f01a45f004040514f004f01a45f00404",
INIT_17 => X"58f01ac5f08405840914f01ac5f08405840414f01a45f004040514f0a0f01a45",
INIT_18 => X"14f005f005528c0bf01a45f00405040914f01a45f004040514f09c8780070977",
INIT_19 => X"1a45f00404051406f0f00512f005f004c5840c02f005f004c5041a45f0040504",
INIT_1A => X"800447877c0604040703020101030206005757560600061a45f004050414f005",
INIT_1B => X"f004040514f080f080f066f05505959487800447877a078b090b7cf005059487",
INIT_1C => X"0414f0050a1a45f004040514f0f005f0c80c07f00514f00405f4074504041a45",
INIT_1D => X"09090909090b7975716d696561363232366165696d717579296ef01a45f00405",
INIT_1E => X"090b090c090a0909090909090909090909090a09090909090909090909090909",
INIT_1F => X"5b006e6470555b31326520656c6249480b090a090909090c0909090909090909",
INIT_20 => X"6266697729286561612072205b006965205b007565205b4d456172205b006f42",
INIT_21 => X"00000000000000782064007820627c203a68746c006972700a627362002d2e72",
INIT_22 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_23 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_24 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_25 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_26 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_27 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_28 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_29 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2F => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_30 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_31 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_32 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_33 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_34 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_35 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_36 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_37 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_38 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_39 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3F => X"0000000000000000000000000000000000000000000000000000000000000000")
   port map (
      DO   => data_read(23 downto 16),
      DOP  => open, 
      ADDR => address(12 downto 2),
      CLK  => clk, 
      DI   => data_write(23 downto 16),
      DIP  => ZERO(0 downto 0),
      EN   => enable,
      SSR  => ZERO(0),
      WE   => write_byte_enable(2));

   RAMB16_S9_inst2 : RAMB16_S9
   generic map (
INIT_00 => X"741131217d0100f1418104009101000107a70500c105401105017d050010c100",
INIT_01 => X"f101f1d7f7814101f74101f10427c1f981f101f1d747f781410100840a010551",
INIT_02 => X"070000a7000707070000014181c1014181c127c1a1800481a1554004c181f981",
INIT_03 => X"c004090407c00a05050600e70520e65131219181114101000700070707000005",
INIT_04 => X"00014181c10141810ac1f7d7c717f70707fa0a07f70404f71935aaa4c0090505",
INIT_05 => X"07a517f71507c0a5100005050500000000070515a707151500059ff929d05f05",
INIT_06 => X"0007e517f6150506c0100005a5059f009f16b00510a000a006071517f5b6b600",
INIT_07 => X"1000000715b5b51707a517f7150507c0100005a55f0010000000071517f5b7b7",
INIT_08 => X"05554505df2b84df194407c08090f090d0a0000091118171615141312181011f",
INIT_09 => X"0181c1014181c101814104c14505449f1ff90cdf005f098505e995f5e995f59b",
INIT_0A => X"9f010004a705f0118101000181c10507870104041f14000501df811101a00100",
INIT_0B => X"0707d726151707d7b60700000080dfdf00000181c1050787010404df14050001",
INIT_0C => X"f41f849f3005f47791110400810100079fd7460706868505f7f5c7e6d61636f5",
INIT_0D => X"04f4049ff91f899f050630f7057721918111010700000181f48741c1041f009f",
INIT_0E => X"df0560f9057731918111090021010001f701418781c107009414a49f00941404",
INIT_0F => X"001f01f7a087c1014181c10700945f14041f099ff5895ff9770409f987692009",
INIT_10 => X"4181c1f557a46b84851f3005dff42084051f1005dfe7d70007e7979181110107",
INIT_11 => X"0100030100004181c15f00068006a684851f7005dff46084051f5005df400001",
INIT_12 => X"50008fa005048f1484300005045f1404a05fcf00918171615141312191811105",
INIT_13 => X"000504cf1444a00005048f14c4a00005044f14c4a00005040f1444a000e00080",
INIT_14 => X"0f1484a000000705a7258700ace44f05cf4fa005044f14c4a00005040f1484a0",
INIT_15 => X"a000df141a0705facf054f04f4c009840300058f05048f1404a000001f040504",
INIT_16 => X"0f14a08405001f05044f1404a0009f059f0504cf1404a0009f051f05044f1404",
INIT_17 => X"30df05040f14a08405001f05044f14a00405005f05048f1404a000dfa4df0504",
INIT_18 => X"001f0ccfa0a009058f0504cf14a0040500cf05040f1404a0005ff917e70434f5",
INIT_19 => X"05048f1404a0000adf4f00240f005f14041464240f005f10040c05040f140004",
INIT_1A => X"e7140786440000018141e1c101f1d150c10a8a8ab0c11005044f140004001f0a",
INIT_1B => X"0f144400009f07df075f449f05010b9717e714078944011b0000449f0001f417",
INIT_1C => X"04000f0a1a0504cf1484d0001f4fa0df770434cfc0948f14e0fa05040c0c0504",
INIT_1D => X"0000000000007a76726e6a6662373331353964686c70747800759f05044f1400",
INIT_1E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_1F => X"620061206c5d7536207000726f6f534600000000000000000000000000000000",
INIT_20 => X"696f6e613a6873640064695d77006c6d5d66006d6d5d6400506d6f5d70006f5d",
INIT_21 => X"0000000000000029286100292879000000656865006e6172006f0079003e0079",
INIT_22 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_23 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_24 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_25 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_26 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_27 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_28 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_29 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2F => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_30 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_31 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_32 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_33 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_34 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_35 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_36 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_37 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_38 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_39 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3F => X"0000000000000000000000000000000000000000000000000000000000000000")
   port map (
      DO   => data_read(15 downto 8),
      DOP  => open, 
      ADDR => address(12 downto 2),
      CLK  => clk, 
      DI   => data_write(15 downto 8),
      DIP  => ZERO(0 downto 0),
      EN   => enable,
      SSR  => ZERO(0),
      WE   => write_byte_enable(1));

   RAMB16_S9_inst3 : RAMB16_S9
   generic map (
INIT_00 => X"1a02010301000000010205f002fd00010e0e01f00001320084ff0100000fff50",
INIT_01 => X"0000004000000000fa0000000507000400000000400100000000031a84000001",
INIT_02 => X"01f0000ef0fe0801f0000301010102020202f90000280000000123000000fc00",
INIT_03 => X"0c0000000000ea000000000a0002ff01010100000001fe000ef0fe0401f00004",
INIT_04 => X"00020000000101010001fefe0000ff0000020000ff06fcfe0002004008000000",
INIT_05 => X"04fe00ff0004010000020006040000000000fe00000000000002f9000002fd00",
INIT_06 => X"0002fe00ff000002000002040400fd00f90040fa0040004000fe000000400000",
INIT_07 => X"000000fe0040000000fe00ff0000020000020404fd0000000000fe0000004000",
INIT_08 => X"fd050500d10700cf00000001000100000000000002020101010101010302fdfe",
INIT_09 => X"030000010101010202020002fb0000cccaff00ca02cb00fb00fafaf9fcfcfbfc",
INIT_0A => X"c20001000400000202fd00030202fefe00020101c300000200c802020000fd00",
INIT_0B => X"0908080000000908ff0905f00000fab90300030202fefe00020101bc00020000",
INIT_0C => X"0ff500f5000008ff000009f000ff0000fa080009fa4101020f0f0800ff0000ff",
INIT_0D => X"01ff02ed0fee00ee0000000800ff01000000ff09f00001000800000009f400f4",
INIT_0E => X"e400000800ff0100000009f001fe000108000000000009f0fe0000eb00000001",
INIT_0F => X"f08502080000000101010109f0fee00000e10ce10f40e208ff04090800000009",
INIT_10 => X"000000000b00b10000df0000df00000101e10000e108ff00090800000000ff09",
INIT_11 => X"f90000014000000000dd40010001000000d90000d900000101db0000db000001",
INIT_12 => X"0300fe00fe00ff00fd0500fe008100fc00eced00050505050505050706060610",
INIT_13 => X"00fe00f600020000fe00f800000000fe00fa00ff0000fe00fc00fe0000050100",
INIT_14 => X"ee000900004000000000ee00f4fbf400f4f200fe00f300040000fe00f5000300",
INIT_15 => X"0000fc000034003feafeea38ff000900000000edfe00eb0007000040f000fe00",
INIT_16 => X"de00000d00008afe00e000060000f2008cfe00e200060000f7008ffe00e50006",
INIT_17 => X"d980fe00d700000c000083fe00d900000b000085fe00db00060000df0087fe00",
INIT_18 => X"008e00ce00d20000fafe00d000000b0000fcfe00d300060000d7fe000000010f",
INIT_19 => X"fe00c6000a0000cafdc802ffc902890000001303cb028b000000fe00cd00020c",
INIT_1A => X"000000000740000400010000000000fb000100010600fbfe00c4000209008000",
INIT_1B => X"b6000c0200f900fd00bbfd97010001fe00000000000300004000bf9b0000fe00",
INIT_1C => X"0900e90000fe00af00080200cab102b4e30041b207feb3000200fe000001fe00",
INIT_1D => X"0000000000000077736f6b6763383430343863676b6f7377006caffe00ad0002",
INIT_1E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_1F => X"2c0072626f202c0032200020616f432d00000000000000000000000000000000",
INIT_20 => X"6e726769006573640061742020006c2020200070202020005220672020007420",
INIT_21 => X"000000000000003a6874003a687400000078206e00676d6f006f00740020002e",
INIT_22 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_23 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_24 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_25 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_26 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_27 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_28 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_29 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_2F => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_30 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_31 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_32 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_33 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_34 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_35 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_36 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_37 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_38 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_39 => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3A => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3B => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3C => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3D => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3E => X"0000000000000000000000000000000000000000000000000000000000000000",
INIT_3F => X"0000000000000000000000000000000000000000000000000000000000000000")
   port map (
      DO   => data_read(7 downto 0),
      DOP  => open, 
      ADDR => address(12 downto 2),
      CLK  => clk, 
      DI   => data_write(7 downto 0),
      DIP  => ZERO(0 downto 0),
      EN   => enable,
      SSR  => ZERO(0),
      WE   => write_byte_enable(0));

end; --architecture logic