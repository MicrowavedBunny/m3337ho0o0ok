### Meathook v7.2

This version of Meathook was created by chrispy. It was released on November 15, 2021. I take no credit for the creation of this tool.

### Instructions

Copy the "XINPUT1_3.dll" file into your Doom Eternal directory. Overwrite the existing file if prompted.

### Known Issues with Game Update v6.66

Certain mods may cause the game to crash with an Engine Error. An example of the error is:
`component 20 (aicomponent/jetpack/revenant_test) on 'master_level_ai_heavy_revenant_retro' has an invalid component id`

This is a problem with version 7.1 of Meathook. If you encounter this error, please download the newest version (v7.2).

### Changelog

- Fixes `chrispy` command which broke in v6.66 game update
- Adds several new commands, use `find mh_` in console to see a list.

### Console Commands

Command | Description
------------ | -------------
chrispy | chrispy \<entitydef\> \<optional xyz position\> - spawns an entity at the position
idlib_dump | idlib_dump
mh_active_encounter | Get the list of active encounter managers
mh_ang2mat | mh_ang2mat pitch yaw roll : converts the pitch, yaw and roll values for idAngles to a decl - formatted matrix, copying the result to your clipboard
mh_angleincr | <double> amount to inc/dec by with angle editing
mh_cpuinfo | takes no args, dumps info about your cpu for dev purposes
mh_current_checkpoint | Get the current checkpoint name
mh_dump_bmodel | <name> <output path> <skip_compression> Finds a staticmodel and then executes writestaticbmodel to the provided path
mh_dumpeventdefs | mh_dumpeventdefs <as enum = 0/1>
mh_dumpmap | Dump current idMapLocal to a .map file.
mh_dumppropidxinfo | Debug command for dumping the corresponding addresses/rvas for property indices
mh_editor | Sets up the editor session
mh_editor_keys | tells you editor stuff
mh_editor_spawn | Spawns an entity, saving it to the map and grabbing it for manipulation
mh_end_spawnrec | No args, closes current spawnfile
mh_force_reload | Force reload current level
mh_gencvarset | Regenerate doom_eternal_cvars_generated.cpp/hpp for mh build
mh_genpropset | Regenerated doom_eternal_properties_generated.cpp/hpp for use in mh builds. not for users
mh_grab | Grab an object
mh_killAi | Kills all living ai
mh_kw | Searches all types, enums, typedefs, their comments, field names, typename, template args, eventdefs, vtbl names, cvar names, cvar descriptions for the provided keywords
mh_list_entity_types | <filter> lists the names of all subclasses of idEntity with optional filter
mh_list_resource_lists | lists all resource lists by classname/typename, copying the result to the clipboard (the clipboard might not be helpful here)
mh_list_resources_of_class | <resourcelist classname> lists all resources in a given list, copying result to clipboard
mh_locate_fspec_char_uses | <char> Finds all usages of a provided char in event formatspecs/rettypes
mh_optimize | Patches the engine to make stuff run faster. Do not use online, might result in slightly different floating point results (probably not though)
mh_printentitydef | Print the entitydef of the entity with the provided name to the console
mh_randomact | <distance> <scalar> uses scalar + random values to randomly change the color, scale, and velocity of all entities within distance from player
mh_reload_decl | mh_reload_decl <classname(ex:idDeclWeapon)> <decl path>
mh_removeAi | Removes all living ai
mh_ScriptCmd | <event> <args> ai_ScriptCmd resurrected, now copies the results of the eventcall to your clipboard for chaining commands together
mh_ScriptCmdEnt | <entity> <event> <args> ai_ScriptCmdEnt resurrected, now copies the results of the eventcall to your clipboard for chaining commands together
mh_set_charscaling | <w> <h> smallchar w/h override
mh_spawnfile | <spawn file path> spawns the entities at the positions from the file
mh_spawninfo | Copy your current position and orientation, formatted as spawnPosition and spawnOrientation to the clipboard
mh_spmap | <map name> shortcut for map maps/game/sp/<map name>/<map name>
mh_start_spawnrec | <spawn file path> starts recording all chrispy/rechrispy spawns/spawn positions to a file for later exec by mh_spawnfile
mh_test_genbmodel | <obj path> <output path> (YOU MUST BE ON V1 WITH RANDOMBASEADDR FLAG OFF ON EXE FOR THIS RIGHT NOW) generate bmodel in standalone resource from .obj
mh_testgui | test
mh_testmaterial | Takes one arg, a material name. Renders the material to the test window. Passing no args clears the test window
mh_type | Dump fields for provided class
noclip | Toggle noclip
notarget | Toggle notarget
rechrispy | Repeats last usage chrispy command with same args
