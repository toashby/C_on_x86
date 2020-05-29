#define FB_GREEN 2
#define FB_DARK_GREY 8
#define FB_BLACK 0

char *fb = (char *) 0x000B8000;

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in framebuffer
 *  @param c  The character
 *  @param fg The fg color
 *  @param bg The bg color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
	//fb[0] = 'A';
	//fb[1] = 0x28;
	fb[i] = c;
	fb[i + 1] = ((fg & 0x0F) << 4 | (bg & 0x0F));
}

//Erites to top line of the screen
void fb_write_string( int colour, const char *string )
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
        *video++ = colour;
    }
}

// clear the screen
void fb_clear(){
    for(int i = 0; i < 3998; i+=2){
        fb_write_cell(i, 0, FB_BLACK, FB_DARK_GREY);
    }
}

/* C function */
int sum_of_three(int arg1, int arg2, int arg3)
{
    fb_clear();

	char vv[] =  "Hello world_";
	fb_write_string(3, vv);
	
	fb_write_cell(24, 'A', FB_GREEN, FB_DARK_GREY);
	fb_write_cell(26, 'K', FB_GREEN, FB_DARK_GREY);

	fb_write_cell(158, '$', FB_GREEN, FB_DARK_GREY);
	fb_write_cell(3998, 'K', FB_GREEN, FB_DARK_GREY);

    return arg1 + arg2 + arg3;
}
