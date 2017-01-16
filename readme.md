
## Install Fork of dwm

```
git clone 'https://github.com/namjul/dwm' ~/.dwm
cd ~/.dwm
sudo apt build-dep dwm
sudo make clean install
```

## Install Fork of dmenu

```
git clone 'https://github.com/namjul/dmenu' ~/.dmenu
cd ~/.dmenu
sudo apt build-dep dmenu
sudo make clean install
```

## Install Helper Programs

`sudo apt install feh conky i3lock rofi`


## Add dwm Executables to your PATH

Add ~/.dwm/bin to your PATH:

`echo 'PATH="$HOME/.dwm/bin:$PATH"' >> ~/.xprofile`

## Add the Desktop Entry Specification

`sudo ln -s ~/.dwm/dwm.desktop /usr/share/xsessions/dwm.desktop`

## Nautilus without a desktop


`gsettings set org.gnome.desktop.background show-desktop-icons false`
