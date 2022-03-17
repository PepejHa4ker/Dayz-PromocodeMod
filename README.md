# PromocodeMod is a server mod that allows you to create and flexibly configure personal promocodes for players.
    It allows to:
        - Spawn items with attachments (e.g. Riffle with the scope and magazine)
        - Set promocode max usages per player (Global max usages in future)
        - Set promocode cooldown per player (Global cooldowns in future) 
        - Create temp promocodes. Temporarily give players access to promocodes, after the expiration date, the promocode will automatically become unavailabler.
How to create promocode:
       - Go to server profile folder and open the PromocodeMod folder
       - config.json allows you to change base promocode command
       - Promocode folder contains all promocodes. To create a new one you have to create new .json file (e.g. first_promocode.json where first_promocode is a promocode id) and set up new promocode 
Example promocode: (start.json file)
`
{
    "entry_id": "start",         
    "duration_minutes": -1,
    "public": 1,
    "max_usages": 1,
    "items": [
        {
            "attachments": [],
            "class_name": "Apple",
            "amount": 3
        },
        {
            "attachments": [],
            "class_name": "Mag_STANAG_60Rnd",
            "amount": 1
        },
        {
            "attachments": [],
            "class_name": "Ammo_556x45",
            "amount": 3
        }
    ],
    "weapons": [
        {
            "attachments": [
                {
                    "attachments": [],
                    "class_name": "ACOGOptic",
                    "amount": 1
                }
            ],
            "class_name": "M4A1",
            "change_fire_mode": 0,
            "fire_mode": 1,
            "attach_magazine": 1,
            "magazine_class_name": "Mag_STANAG_60Rnd"
        }
    ],
    "players": []
}
`
