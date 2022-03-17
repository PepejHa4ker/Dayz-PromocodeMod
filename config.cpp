class CfgPatches
{
	class PromocodeMod
	{
	};
};
class CfgMods
{
	class PromocodeMod
	{
		name="PromocodeMod";
		author="GOPAtyCh";
		type="mod";
		dependencies[]=
		{
			"Game",
			"Mission",
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				files[]=
				{
					"PromocodeMod/scripts/3_Game"
				};
			};
			class missionScriptModule
			{
				files[]=
				{
					"PromocodeMod/scripts/5_Mission"
				};
			};
			class worldScriptModule
			{
				files[]=
				{
					"PromocodeMod/scripts/4_World"
				};
			};
		};
	};
};
