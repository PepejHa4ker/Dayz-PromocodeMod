class PromocodeModServerSettings 
{
	private static string CONFIG_DIR = "$profile:PromocodeMod";
	private static string CONFIG_PATH = CONFIG_DIR + "\\config.json";

    protected string promocode_command;
	protected bool cancel_equip_on_respawn_set;


    string GetPromocodeCommand()
    {
        return promocode_command;
    }
	
	bool CancelEquipOnRespawnSet() 
	{
		return cancel_equip_on_respawn_set;
	}


	void Save() 
	{
        
        if ( !FileExist( CONFIG_DIR ) ) 
        {
            MakeDirectory ( CONFIG_DIR );
        }
        JsonFileLoader<PromocodeModServerSettings>.JsonSaveFile ( CONFIG_PATH, this );
        
    }

    static PromocodeModServerSettings Get()
     {

        auto settings = new PromocodeModServerSettings();

        if ( FileExist ( CONFIG_PATH ) ) 
        {
            JsonFileLoader<PromocodeModServerSettings>.JsonLoadFile ( CONFIG_PATH, settings );
        }

        return settings;
    }
}

static ref PromocodeModServerSettings g_PromocodeModServerSettings;
static PromocodeModServerSettings GetPromocodeModServerSettings()
{
    if ( !g_PromocodeModServerSettings )
    {
        g_PromocodeModServerSettings = PromocodeModServerSettings.Get();
    }
    return g_PromocodeModServerSettings;
}