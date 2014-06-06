#Overview
A collection of scripts and ideas to make tiling window managers more accessible (read more mouse-friendly), hopefully giving less "hobbyist" people the chance to experiment with tiling and the will to go further, such as learning, creating and tweaking keybinds.

For more advanced users, a GUI menu could find its use too, not as a way to do basic operations, but as a way to call scripts to do custom window manipulations that are elaborate but too rare to deserve a specific accessible keybind or to let you remember it.


#Scripts and menus
##MouseLaunch
*Original idea by Kamiru*

![Screenshot](https://raw.github.com/tatou-tatou/Themes/master/Mousse/Previews/LaunchMenu.gif)

The script split the window in the appropriate direction depending on where your cursor is located in the window. A menu will then spawn where your pointer is, asking you what program you want to launch there.

That's probably the only way to make manual tiling work with a mouse.

It forces you to use manual tiling though, so you lose the hybrid approach of bspwm, the consequence being that you are stuck more often in "annoying" layouts that can get tricky to get out.

The `LaunchMenu` file here is an example menu, but you will have to edit the script for it to point to your own myGtkMenu file.

It depends on `xdotool`, `xwinfo` and `mygtkmenu`.

##BspwmMenu
![Screenshot](https://raw.github.com/tatou-tatou/Themes/master/Mousse/Previews/BspwmMenu.png)

A menu file for myGtkMenu. Make it spawn by binding a keybind (for example `super + Button2`) to `mygtkmenu /path/to/BspwmMenu`

It contains what I consider to be the essential/most basic controls to manipulate the window layout in bspwm, organized in an ergonomic way.

It being easier to do a mistake in a manual tiling environment than in a layout-based tiling environment due to its fundamental approach, I plan to add commands to automatically get out of "tricky" situations, in order not to frustrate the user.

The "hybrid" tiling of bspwm solves that, but the `MouseLaunch` script forces to use manual tiling.

##bspwm-zenity
A script to do various actions like adding, removing or renaming workspaces through a GUI interface.

It uses `zenity` and is called by `BspwmMenu`.


##MouseCenter
It centers the mouse in the focused window. If one depends on his mouse more, it might be useful to have.

Depends on `xwinfo` and `xdotool`.


#Tools
##MyGTKmenu
The simplest way to put a lot of functionality in a mouse-driven interface is to use a menu. MyGTKmenu can appear where the cursor is, meaning it will be perfect for the task.

The menu must be clear and not cluttered. The most basic features should be accessible either in the main menu or in the first level of the submenus. More advanced features should not hide them and can appear deeper in the submenu hierarchy.

MyGTKmenu would serve both as a way to manipulate the window layout and to launch programs in specific (tiled) locations.

##Bspwm
- Bspwm is EWMH compliant. It makes you able to use tint2, the xfce-panel or a dock like plank, docky or AWN without issues. Additionally, the EWMH compliance allows the full use of xdo, wmctrl, xdotool, devilspie... All those tools can help making a more mouse-enabled interface.
- Bspwm is also client-controlled, meaning it's very easy to make the window and desktop manipulation events happen by sending commands through mygtkmenu or scripts called by mygtkmenu.
- Bspwm has a sane out-of-the-box behavior towards transient floating dialogs, contrary to the other client-controlled tiling WM I know of.

For those three reasons, I think it's the most adapted to make it mouse-friendly.

Bspwm does have a few problems with user-friendliness though:
- Manual tiling is less mouse-friendly than layouts.
- Non-Arch users seem to have difficulties installing it.

##Sxhkd
Sxhkd is the recommended keybind daemon for Bspwm. Written by the same developper, it allows some very interesting keybinds (like chains or vim-like "modes") and the use of mouse buttons.

If the interface becomes mouse driven, the program-launcher menu and the window-manipulation menu become more important than resizing windows. In order of importance, I would suggest:
- `<ModKey> + Left Click` to move the windows.
- `<ModKey> + Right Click` to spawn the program launching menu.
- `<ModKey> + Middle Click` to spawn the window-manipulation menu.
- Then, `<ModKey1> + <ModKey2> + Click` to resize.

Maybe, `ModKey + Scroll` to switch workspaces.

For multitouch touchpads it's a bit different. Since the `Middle Click` is (in my opinion) long to do and not very precise (three finger tap), those menus should be bound on more appropriate buttons, like the `Left Click` (one-finger tap).

I think those settings are adapted for a right-handed person:
- `<ModKey> + Left Click` to move the windows (the same).
- `Mod5 + Left Click` to launch programs. `Mod5` (Alt_gr) is on the right side of the keyboard, making it easy for a right-handed person to keep it pressed while doing a single tap on the touchpad with the same hand.
- `Mod5 + <the ModKey next to it> + Left Click` to spawn the window-manipulation menu.
- A combination of two modkeys on the left size of the keyboard and a left click to resize windows.

With a multitouch touchpad, other things could be done too. For example switching to the next or previous workspace can be bound to a three-finger swipe. The same for up and down swipes that could trigger monocle or windows visibility.
