#Overview
A collection of scripts and ideas to make tiling window managers more accessible (read more mouse-friendly), hopefully giving less "hobbyist" people the chance to experiment with tiling and the will to go further, such as learning, creating and tweaking keybinds.

As most tiling WM don't even let you do "advanced" window manipulation with a mouse, a lot of "experienced" tiling WM users convinced themselves that mouses were for baby-duck retards and that they never need one in the first place. I agree that keyboard is faster for everything (as long as the said keyboard is already under your fingers), but you *should* be given the option to use your mouse if you ever want to.

For example, if you already have a hand on your mouse, why should you move it away to do a keybind or a chain of keybind needing your mouse hand to be really efficient? Especially if your hand will go back to the mouse as soon as the keybind is done.

And what if you are showing your current work to a few people and you are not near the keyboard? A mouse is easy to grab, asking for people to move so you can access the keyboard and change the window layout or close something is dumb. You should always be given the option to use a mouse.

[I made a screencast of a potential tiling WM mouse-centric workflow.](http://a.pomf.se/axlqcn.webm) *(webm)*

#Scripts and menus
##MouseLaunch
*Original idea by Kamiru*

![Screenshot](https://raw.github.com/tatou-tatou/Themes/master/Mousse/Previews/LaunchMenu.gif)

The script split the window in the appropriate direction depending on where your cursor is located in the window. A menu will then spawn where your pointer is, asking you what program you want to launch there.

That's probably the only way to make manual tiling work with a mouse.

It forces you to use manual tiling though, so you lose the hybrid approach of bspwm, the consequence being that you are stuck more often in "annoying" layouts that can get tricky to get out. Usually, you just have to make tree rotations though, or to use a "Move to manual split".

The `LaunchMenu` file here is an example menu, but you will have to edit the script for it to point to your own myGtkMenu file.

It depends on `xdotool`, `xwinfo` and `mygtkmenu`.

*Note:* if you close the menu without opening anything, the presel signal will remain. I solved that by **patching mygtkmenu** to send a non-zero return code if it's closed without launching anything. **I suggest you to do the same.**

*TODO: Make it work even if one disables `focus_follows_pointer`.*

##BspwmMenu
![Screenshot](https://raw.github.com/tatou-tatou/Themes/master/Mousse/Previews/BspwmMenu.png)

A menu file for myGtkMenu. Make it spawn by binding a keybind (for example `super + Button2`) to `mygtkmenu /path/to/BspwmMenu`

It contains what I consider to be the essential/most basic controls to manipulate the window layout in bspwm, organized in a semi-ergonomic way (currently working on that).

It being easier to do a mistake in a manual tiling environment than in a layout-based tiling environment due to its fundamental approach, I plan to add commands to automatically get out of "tricky" situations, in order not to frustrate the user.

The "hybrid" tiling of bspwm solves that, but the `MouseLaunch` script forces to use manual tiling.

####Potential improvements
The current menu is too long and cluttered, it should *only* contain **window**-related commands:
- Closing windows.
- Changing window state (floating, etc...)
- Moving to other desktops.

![Screenshot](https://raw.github.com/tatou-tatou/Themes/master/Mousse/Previews/apple-like-menu.png)

Anything global should be in a "Start Menu" near the workspace list (like above) or have a dedicated button or menu accessible from the panel:
- Adding/renaming/removing/swapping desktops or moving them to another monitor.
- Cancelling all manual splits.
- Flip or rotate desktop.
- Changing window gap, border width or colors.
- Balance/Equalize desktops.

Flip and rotate desktops are *very* important actions in a manual tiling WM, they should be given special importance. Maybe dedicated icons in the panel, kinda like how Awesome has a layout changer in its panel.

Here's an example of how it could be done (from my Stendhal Theme):

![Desktop](https://raw.github.com/tatou-tatou/Themes/master/Mousse/Previews/desktop-controls.png)

Whenever they are used, rotate and flip are often done in succession, you rotate one time, you flip... A menu would be frustratingly slow.

In my opinion, rotate and flip are the only commands that are critical enough to warrant a semi-permanent shortcut in the panel. All others are punctual and should therefore stay in a global menu.


##bspwm-zenity
A script to do various actions like adding, removing or renaming workspaces through a GUI interface.

It uses `zenity` and is called by `BspwmMenu`.


##MouseCenter
It centers the mouse in the focused window. If one depends on his mouse more, it might be useful to have.

Depends on `xwinfo` and `xdotool`.


#Tools
Why those tools and not others?

##MyGTKmenu
The most simple way to put a lot of functionality in a mouse-driven interface is to use a menu. MyGTKmenu can appear where the cursor is, meaning it will be perfect for the task.

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
- No minimizing.

The only decent alternative to bspwm in terms of user-friendliness is AwesomeWM. Awesome will work with anything, supports everything, can minimize, has a very good panel out of the box (and can use stand-alone panels like the xfce one) and has a right click menu. It does have some problems though, the main one being that it is written and configured in lua and that it is not client-controlled like bspwm.

##Sxhkd
Sxhkd is the recommended keybind daemon for Bspwm. Written by the same developer, it allows some very interesting keybinds (like chains or vim-like "modes") and the use of mouse buttons.

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
- A combination of two modkeys on the left side of the keyboard and a left click to resize windows.

With a multitouch touchpad, other things could be done too. For example switching to the next or previous workspace can be bound to a three-finger swipe. The same for up and down swipes, which could trigger monocle or window visibility.


##Skippy-xd
It's a stand-alone expose-like program. It works well even if it looks worse than the true thing. There are other stand-alone expose-like programs, but I don't know them well.

When in monocle mode, a mouse user might enjoy it more than turning monocle off and on again or than using his taskbar or some dmenu script to focus the window he wants.

I haven't tried, but I guess you can use xdotool to launch it like on OSX, through an "active corner". Else, you can always make a dedicated shortcut to click on in your panel or dock.
