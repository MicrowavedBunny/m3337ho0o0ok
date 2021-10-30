Forked/copied from FishnCrisps, with latest pull request applied (for Doom Eternal v6.0 support). This repository is not actively maintained, and exists for archival/backup purposes.

### Instructions

Copy the "XINPUT1_3.dll" file into your Doom Eternal directory. Overwrite the existing file if prompted.

### Known Issues with Game Update v6.66

- `chrispy` command doesn't work properly, entities are spawned at coords 0, 0, 0. 
- `mh_optimize` command has been removed due to crash/instability.

### Changelog

- Add compatibility with EternalModInjector online safety features
- Fix stability/crash issue with `mh_active_encounter` command
- Removed `mh_optimize` command due to crash/instability.

### Console Commands

Command | Description
------------ | -------------
chrispy | chrispy \<entitydef\> \<optional xyz position\> - spawns an entity at the position
gibalicious | Instantly gibs all AI in the world
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
