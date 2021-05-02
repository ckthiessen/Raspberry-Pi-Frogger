/* GIMP RGB C-Source image dump (bus_back.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[64 * 36 * 2 + 1];
} bus_back_img = {
  64, 36, 2,
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000@\012"
  "@\012@\012@\012@\012@\012@\012@\012@\012@\012@\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000@\012@\012@\012@\012@\012@\012@\012@\012@\012"
  "@\012@\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000@\012@\012@\012@\012@\012@\012@\012@\012@\012@\012@\012\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X"
  "\033X\000\000\000\000\000\000\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363\300\363"
  "\300\363\300\363\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\033X\033X\033X\033X\033X\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000@\012@\012@\012@\012@\012"
  "@\012@\012@\012@\012@\012@\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000@\012@\012@\012@\012@\012@\012@\012@\012@\012@\012@\012\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000@\012@\012@\012"
  "@\012@\012@\012@\012@\012@\012@\012@\012\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
};

