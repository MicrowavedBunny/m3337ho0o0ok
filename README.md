### Meathook v7.1

This version of Meathook was created by chrispy. It was released on November 15, 2021. I take no credit for the creation of this tool.

### Instructions

Copy the "XINPUT1_3.dll" file into your Doom Eternal directory. Overwrite the existing file if prompted.

### Known Issues with Game Update v6.66

Certain mods may cause the game to crash with an Engine Error. An example of the error is:
`component 20 (aicomponent/jetpack/revenant_test) on 'master_level_ai_heavy_revenant_retro' has an invalid component id`

If you encounter this error, please notify the mod creator. You will either need to remove meathook or downgrade to a previous version of meathook to resolve the issue.

### Changelog

- Fixes `chrispy` command which broke in v6.66 game update
- Adds several new commands, use `find mh_` in console to see a list.

### Console Commands (NOT YET UPDATED FOR v7.1)

Command | Description
------------ | -------------
chrispy | chrispy \<entitydef\> \<optional xyz position\> - spawns an entity at the position
idlib_dump | idlib_dump
mh_active_encounter | Get the list of active encounter managers
mh_ang2mat | mh_ang2mat pitch yaw roll : converts the pitch, yawand roll values for idAngles to a decl - formatted matrix, copying the result to your clipboard
mh_current_checkpoint | Get the current checkpoint name
mh_dumpmap | Dump current idMapLocal to a .map file.
mh_force_reload | Force reload current level
mh_printentitydef | Print the entitydef of the entity with the provided name to the console
mh_reload_decl | mh_reload_decl <classname(ex:idDeclWeapon)> <decl path>
mh_spawninfo | Copy your current position and orientation, formatted as spawnPosition and spawnOrientation to the clipboard
mh_type | Dump fields for provided class
noclip | Toggle noclip
notarget | Toggle notarget
