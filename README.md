
## PromocodeMod is a server mod that allows you to create and flexibly configure personal promocodes for players.
[Steam Workshop](https://steamcommunity.com/workshop/filedetails/?id=2780196589)

### It allows to:
- Spawn items with attachments (e.g. Riffle with the scope and magazine)
- Create spawn sets (items will spawn after player respawn)
- Set promocode max usages per player (Global max usages in future)
- Set promocode cooldown per player (Global cooldowns in future) 
- Create temp promocodes. Temporarily give players access to promocodes, after the expiration date, the promocode will automatically become unavailabler.

### How to create promocode:
- Go to the server profile folder and open the PromocodeMod folder
- config.json allows you to change base promocode command
- Promocode folder contains all promocodes. To create a new one you have to create new .json file (e.g. first_promocode.json where first_promocode is a promocode id) and set up new promocode 
### Usage:
If you're using command mode:
<p>You have to enter the command defined in the config.json file and then the id of the promocode (e.g. .promocode start)</p>

If you're using on respawn mode:
<p>Just die</p>

## Example promocode: (Promocodes/start.json file)

```json
{
    "entry_id": "start",         
    "duration_minutes": -1,
    "public": 1,
    "spawn_on_ground": 0,
    "only_on_respawn": 1,
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
```

## Example personal promocode (Promocodes/GOPAtyCh.json file)
```json
{
    "entry_id": "GOPAtyCh",
    "duration_minutes": 30,
    "public": 0,
    "spawn_on_ground": 0,
    "only_on_respawn": 0,
    "max_usages": -1,
    "items": [
        {
            "attachments": [],
            "class_name": "",
            "amount": 3
        },
        {
            "attachments": [],
            "class_name": "Mag_STANAG_60Rnd",
            "amount": 3
        },
        {
            "attachments": [],
            "class_name": "Medical_Bandage",
            "amount": 1
        },
        {
            "attachments": [],
            "class_name": "Medical_VitaminBottle",
            "amount": 1
        },
        {
            "attachments": [],
            "class_name": "AthleticShoes_Black",
            "amount": 1
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
            "change_fire_mode": 1,
            "fire_mode": 2,
            "attach_magazine": 1,
            "magazine_class_name": "Mag_STANAG_60Rnd"
        }
    ],
    "players": [
        {
            "player_id": "76561198400554730",
            "promocode_days": 14,
            "usages": 1,
            "last_use_unix_ts": 703051096,
            "activation_date_unix": 703051000
        }
    ]
}
```
## Example spawn set (SpawnSets/76561198400554730.json file)
```json
{
  "entry_id": "76561198400554730", 
  "promocodes": [
    "start"
  ]
}
```

