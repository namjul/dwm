/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[] = "-*-tamsynmod-medium-r-*-*-18-*-*-*-*-*-*-*";

static const char colors[MAXCOLORS][ColLast][13] = {
    /* border    fg       	bg */
  { "#002b36", "#FFFFFF", "#222222" },        // 01 - regular
	{ "#4d79ff", "#FFFFFF", "#222222" },        // 02 - selected
	{ "#222222", "#FF0000", "#222222" },        // 03 - urgent
	{ "#222222", "#666666", "#222222" }, 				// 04 - occupied
	{ "#222222", "#A82222", "#222222" },        // 05
	{ "#222222", "#4d79ff", "#222222" },        // 06
	{ "#222222", "#349147", "#222222" },        // 07
	{ "#222222", "#333333", "#222222" },        // 08
	{ "#222222", "#DCDCDC", "#222222" },        // 09
	{ "#222222", "#4d79ff", "#222222" },        // 10
	{ "#222222", "#B86A6A", "#222222" },        // 11
	{ "#222222", "#FFFFFF", "#222222" },        // 12
	{ "#222222", "#000000", "#222222" },        // 13

};

static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 8;            /* gaps between windows */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const unsigned int tagspacing = 1;       /* space between tags */
static const unsigned int tagpadding = 5;      /* inner padding of tags */
static const unsigned int taglinepx = 2;        /* height of tag underline */
static const Bool showbar           = True;     /* False means no bar */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool statusmon         = True;     /* False means no statusbar on all monitors? */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",      NULL,       NULL,       1,            False,       -1 },
	{ "Popcorntime",  NULL,       NULL,       1 << 3,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol			gaps		arrange */
  { "þ",      True,   tile },
  { "ý",      False,  NULL },
  { "ÿ",      False,  monocle },
  { "ü",      True,   bstack },
};

/* tagging */
static const Tag tags[] = {
	/* name       layout           mfact    nmaster */
	{ "web",     &layouts[0],     -1,      -1 },
	{ "term",    &layouts[0],     -1,      -1 },
	{ "mail",    &layouts[1],     -1,      -1 },
	{ "media",   &layouts[0],     -1,      -1 },
	{ "misc",    &layouts[0],     -1,      -1 },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* key definitions */

#define NUMCOLORS 13
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[9][ColFG], NULL };
static const char *termcmd[]  = { "uxterm", NULL };
static const char *browser[] = { "firefox", NULL, NULL, NULL, "Firefox" };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
  { MODKEY|ShiftMask,             XK_w,      runorraise,     {.v = browser } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { MODKEY,                       XK_Left,   cycle,          {.i = -1 } },
  { MODKEY,                       XK_Right,  cycle,          {.i = +1 } },
  { MODKEY|ControlMask,           XK_Left,   tagcycle,       {.i = -1 } },
  { MODKEY|ControlMask,           XK_Right,  tagcycle,       {.i = +1 } },
  { MODKEY|ControlMask,           XK_j,      pushdown,       {0} },                                                                                      
  { MODKEY|ControlMask,           XK_k,      pushup,         {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

