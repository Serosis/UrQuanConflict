//Copyright Paul Reiche, Fred Ford. 1992-2002

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef TFB_DRAW_H
#define TFB_DRAW_H

#include "libs/threadlib.h"

typedef void *TFB_Canvas;

typedef enum {
	TFB_SCREEN_MAIN,
	TFB_SCREEN_EXTRA,
	TFB_SCREEN_TRANSITION,

	TFB_GFX_NUMSCREENS
} SCREEN;

typedef struct tfb_palette
{
	UBYTE r;
	UBYTE g;
	UBYTE b;
	UBYTE unused;
} TFB_Palette;

typedef struct tfb_image
{
	TFB_Canvas NormalImg;
	TFB_Canvas ScaledImg;
	TFB_Palette *Palette;
	int colormap_index;
	int scale;
	Mutex mutex;
	BOOLEAN dirty;
} TFB_Image;


// Drawing commands

void TFB_DrawScreen_Line (int x1, int y1, int x2, int y2, int r, int g, int b, SCREEN dest);
void TFB_DrawScreen_Rect (PRECT rect, int r, int g, int b, SCREEN dest);
void TFB_DrawScreen_Image (TFB_Image *img, int x, int y, BOOLEAN scaled, TFB_Palette *palette, SCREEN dest);
void TFB_DrawScreen_Copy (PRECT r, SCREEN src, SCREEN dest);
void TFB_DrawScreen_FilledImage (TFB_Image *img, int x, int y, BOOLEAN scaled, int r, int g, int b, SCREEN dest);
void TFB_DrawScreen_CopyToImage (TFB_Image *img, PRECT lpRect, SCREEN src);
void TFB_DrawScreen_DeleteImage (TFB_Image *img);
void TFB_DrawScreen_WaitForSignal (void);
void TFB_DrawScreen_SetPalette (int paletteIndex, int r, int g, int b);
void TFB_FlushPaletteCache (void);

void TFB_DrawImage_Line (int x1, int y1, int x2, int y2, int r, int g, int b, TFB_Image *dest);
void TFB_DrawImage_Rect (PRECT rect, int r, int g, int b, TFB_Image *image);
void TFB_DrawImage_Image (TFB_Image *img, int x, int y, BOOLEAN scaled, TFB_Palette *palette, TFB_Image *target);
void TFB_DrawImage_FilledImage (TFB_Image *img, int x, int y, BOOLEAN scaled, int r, int g, int b, TFB_Image *target);

void TFB_DrawCanvas_Line (int x1, int y1, int x2, int y2, int r, int g, int b, TFB_Canvas dest);
void TFB_DrawCanvas_Rect (PRECT rect, int r, int g, int b, TFB_Canvas image);
void TFB_DrawCanvas_Image (TFB_Image *img, int x, int y, BOOLEAN scaled, TFB_Palette *palette, TFB_Canvas target);
void TFB_DrawCanvas_FilledImage (TFB_Image *img, int x, int y, BOOLEAN scaled, int r, int g, int b, TFB_Canvas target);

#endif
