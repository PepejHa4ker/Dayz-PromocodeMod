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
			"Mission",
			"World"
		};
		class defs
		{

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
