/* See LICENSE file for copyright and license details. */

/* Status bar colors */
static const char normbordercolor[] = "#696969";
static const char normbgcolor[]     = "#262626";
static const char normfgcolor[]     = "#696969";
static const char selbordercolor[]  = "#696969";
static const char selbgcolor[]      = "#262626";
static const char selfgcolor[]      = "#e0e0e0";

static const char font[]            = "-*-clean-medium-r-*-*-12-*-*-*-*-*-*-*";

static const unsigned int borderpx  = 1;      /* border pixel of windows */
static const unsigned int snap      = 25;     /* snap pixel */
static const Bool showbar           = True;   /* False means no bar */
static const Bool topbar            = True;   /* False means bottom bar */

static const char *tags[] = {" ! ", " @", " #", " $ ", " % "};

/* layout(s) */
static const float mfact      = 0.55;  /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol   arrange function */
	{"~",       tile },  /* first entry is default */
	{"><",      NULL },  /* no layout function means floating behavior */
};

static const Rule rules[] = {
	/* xprop(1):
	 * WM_CLASS(STRING) = instance, class
	 * WM_NAME(STRING) = title
	 */
	/* class   instance   title         tags mask   isfloating   monitor */
	{NULL,     NULL,      "Floating",   0,          True,        -1 },
//	{ "Steam", NULL,       NULL,        0 << 3,     True,        -1 },
};

/* commands */
static const char *browsercmd[]   = { "firefox", NULL };
static const char *termcmd[]      = { "urxvtc", NULL };
static const char *floattermcmd[] = { "urxvtc", "-title", "Floating", "-geometry","90x24+300+200", NULL };
static const char *prtscrcmd[]    = { "/home/rcr/scripts/printscreen", NULL };
static const char *togglemute[]   = { "/home/rcr/scripts/volctrl", "M", NULL };
static const char *voldown[]      = { "/home/rcr/scripts/volctrl", "D", NULL };
static const char *volup[]        = { "/home/rcr/scripts/volctrl", "U", NULL };

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static Key keys[] = {
  /* modifier                     key        function        argument */
  { 0,                            XK_F2,     spawn,          {.v = floattermcmd } },
  { 0,                            XK_F3,     spawn,          {.v = termcmd } },
  { 0,                            XK_F10,    spawn,          {.v = togglemute } },
  { 0,                            XK_F11,    spawn,          {.v = voldown } },
  { 0,                            XK_F12,    spawn,          {.v = volup } },
  { 0,                            XK_Print,  spawn,          {.v = prtscrcmd } },
  { MODKEY,                       XK_F2,     spawn,          {.v = browsercmd } },
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY,                       XK_Return, zoom,           {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
  { MODKEY,                       XK_0,      view,           {.ui = ~(1 << 1) } },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
/*
  { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
  { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
  { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
  { MODKEY,                       XK_space,  setlayout,      {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
*/
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	/* 
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	*/
};
