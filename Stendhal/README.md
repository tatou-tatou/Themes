#Stendhal
![Screenshot](https://raw.github.com/tatou-tatou/Themes/master/Stendhal/Previews/scrot.png)

I use [bspwm](https://github.com/baskerville/bspwm) with [bar-aint-recursive](https://github.com/LemonBoy/bar). Dzen (as a panel) has more interesting features than *bar*, but *bar* can do proper text alignement.

##Panel
Browse the [appropriate folder](http://github.com/tatou-tatou/Themes/tree/master/Stendhal/Panel), it has a few .gif of it in action.

It's clickable, even if I don't click on it often (except for the torrent list and sometimes for the standalone music controls or the keyboard layout switcher).

I worked on its ergonomy recently, so I may use it more often starting from now.

##Dock
It's [plank](https://launchpad.net/plank) with a [custom theme](https://github.com/tatou-tatou/dotfiles/blob/master/.local/share/plank/themes/Tatou/dock.theme) and [patched](https://github.com/tatou-tatou/dotfiles/blob/master/Sources/plank-indicator.patch) to change the shape of the indicators.

The patch adds two new settings that need to be set in the `dock.theme`, `IndicatorHeight` and `IndicatorColor`.

##Notifications
It's [dunst](https://github.com/knopwob/dunst), that I patched ([here](https://github.com/tatou-tatou/dotfiles/blob/master/Sources/dunst-centering_and_padding.patch) or [there](https://github.com/tatou-tatou/dunst)) to have better (in my opinion) padding and to fix centering issues.

My dunstrc is [here](https://github.com/tatou-tatou/dotfiles/blob/master/.config/dunst/dunstrc).

##Icons
I only make new ones as I need them. Because of that, the theme is really incomplete.

I will upload them eventually, but maybe not on github as they are binary files.

##Gtk theme
[201F](https://github.com/tatou-tatou/201F)

##Dmenu
I use dmenu2 and center it like this:

    dmenu_run -i -x 415 -y 330 -w 450 -h 20 -l 4 -fn 'Lucida Grande-8' -nb '#201F1D' -nf '#eddec9' -sb '#8F3724' -sf '#eddec9'

I use the same centering trick for every scripts I use involving dmenu.

If you think dmenu2 is bloat, you can always achieve the same exact look with vanilla dmenu, you will just need to patch it for custom width, x and y positioning and xft or pango.

**Edit** I don't use dmenu2 anymore, now I'm using vanilla dmenu patched for pango (font fallbacks are bliss), x, y, width, height, quiet and mouse. The command is the same, except for `Lucida Grande 8` (no dash with pango).

##Compositor
I use the richardgv-dev branch of compton and apart from preventing tearing, I use it to make fade effects when opening/closing clients and to draw very light shadows on floating windows (not on tiled ones).

My config file is [there](https://github.com/tatou-tatou/dotfiles/blob/master/.config/compton.conf).
