class PMStatic
{
	static int GetUnixNow()
	{
		int year, mon, day, hour, min, sec;
		GetYearMonthDayUTC(year, mon, day);
		GetHourMinuteSecondUTC(hour, min, sec);

		year -= 2000;
		
		return ((year * 365 + mon * 30 + day) * 86400) + sec + min * 60 + hour * 3600;
	}
	
	static void SendPlayerMessage( PlayerBase player, string message )
	{
		GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, new Param1<string>(message), true, player.GetIdentity() );
	}
}