/**
 * @file drw.h
 * @author JeffOfBread (https://github.com/JeffofBread) & https://suckless.org/
 * @brief Header for drw.c; Part of [libsl](https://git.suckless.org/libsl/files.html), a shared library created by suckless to help draw text and other objects to the screen in X11 for their various programs
 * @see https://git.suckless.org/libsl/files.html
 * @version @VERSION
 * @copyright Refer to jdwm's LICENSE file: https://github.com/JeffofBread/jdwm/blob/master/LICENSE
 */

typedef struct {
	Cursor cursor;
} Cur;

typedef struct Fnt {
	Display *dpy;
	unsigned int h;
	XftFont *xfont;
	FcPattern *pattern;
	struct Fnt *next;
} Fnt;

enum { ColFg, ColBg, ColBorder }; /* Clr scheme index */
typedef XftColor Clr;

typedef struct {
	unsigned int w, h;
	Display *dpy;
	int screen;
	Window root;
	Drawable drawable;
	Picture picture;
	GC gc;
	Clr *scheme;
	Fnt *fonts;
} Drw;

/* Drawable abstraction */
Drw *drw_create(Display *dpy, int screen, Window win, unsigned int w, unsigned int h);
void drw_resize(Drw *drw, unsigned int w, unsigned int h);
void drw_free(Drw *drw);

/* Fnt abstraction */
Fnt *drw_fontset_create(Drw *drw, const char *fonts[], size_t fontcount);
void drw_fontset_free(Fnt *set);
unsigned int drw_fontset_getwidth(Drw *drw, const char *text);
unsigned int drw_fontset_getwidth_clamp(Drw *drw, const char *text, unsigned int n);
void drw_font_getexts(Fnt *font, const char *text, unsigned int len, unsigned int *w, unsigned int *h);

/* Colorscheme abstraction */
void drw_clr_create(Drw *drw, Clr *dest, const char *clrname);
Clr *drw_scm_create(Drw *drw, const char *clrnames[], size_t clrcount);

/* Cursor abstraction */
Cur *drw_cur_create(Drw *drw, int shape);
void drw_cur_free(Drw *drw, Cur *cursor);

/* Drawing context manipulation */
void drw_setfontset(Drw *drw, Fnt *set);
void drw_setscheme(Drw *drw, Clr *scm);

Picture drw_picture_create_resized(Drw *drw, char *src, unsigned int src_w, unsigned int src_h, unsigned int dst_w,
				   unsigned int dst_h);

/* Drawing functions */
void drw_rect(Drw *drw, int x, int y, unsigned int w, unsigned int h, int filled, int invert);
void drw_polygon(Drw *drw, int x, int y, int ow, int oh, int sw, int sh, const XPoint *points, int npoints, int shape,
		 int filled);
int drw_text(Drw *drw, int x, int y, unsigned int w, unsigned int h, unsigned int lpad, const char *text, int invert);
void drw_pic(Drw *drw, int x, int y, unsigned int w, unsigned int h, Picture pic);

/* Map functions */
void drw_map(Drw *drw, Window win, int x, int y, unsigned int w, unsigned int h);
