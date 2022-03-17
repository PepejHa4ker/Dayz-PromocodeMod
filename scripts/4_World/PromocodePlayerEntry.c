class PromocodePlayerEntry
{
	string player_id;
	protected int promocode_days;
	int usages;
	int last_use_unix_ts;
	int activation_date_unix;

	
	string GetPlayerId()
	{
		return player_id;
	}

	int GetPromocodeDays()
	{
		return promocode_days;
	}


	int GetLastUseUnix()
	{
		return last_use_unix_ts;
	}
}