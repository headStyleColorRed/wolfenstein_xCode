//
//  map_manager.h
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#ifndef map_manager_h
#define map_manager_h

typedef struct	s_color
{
	int r_color;
	int g_color;
	int b_color;
}				t_color;

typedef struct s_resolution
{
	int width;
	int length;
}				t_resolution;

typedef struct	s_map
{
	char  			*NO_texture;
	char  			*SO_texture;
	char  			*WE_texture;
	char  			*EA_texture;
	char  			*SP_texture;
	char			*map;
	char			*map_file;
	int				map_height;
	int				map_width;
	t_resolution 	resolution;
	t_color			floor_color;
	t_color			ceiling_color;
}				t_map;


/*  M A P   R E A D E R */
char 	*read_map(t_map *raw_map);
void	process_file(char *map_file, t_map *map);
void	file_processor(int argc, char **argv, t_map *map);

/*  M A P   P A R S E R  */
char	*parse_character(char *raw_map, char *chosen_field);
void	parse_cube_map(char *raw_map, t_map *map);

/*  M A P   T E X T U R E	P A R S E R */
void	parse_north_texture(char *raw_map, t_map *map);
void	parse_south_texture(char *raw_map, t_map *map);
void	parse_east_texture(char *raw_map, t_map *map);
void	parse_west_texture(char *raw_map, t_map *map);
void	parse_sprite_texture(char *raw_map, t_map *map);

/*  M A P   R E S T 	P A R S E R */
void	parse_resolution(char *raw_map, t_map *map);
void	parse_floor_color(char *raw_map, t_map *map);
void	parse_ceiling_color(char *raw_map, t_map *map);

/*  M A P   M A T R I X */
void	parse_map(t_map *map);
int		is_map_beggining(char *line);

/*  M A P   S P A C E D   M A T R I X */
void	parse_spaced_map(t_map *map);

/*  M A P   C O N F O R M I N G */
void	check_file_conformity(t_map *map);


/*  M A P   C O N F O R M I N G	   M A P */
void	check_map_right_left_conformity(t_map *map);
void	check_map_top_conformity(t_map *map);
void	check_map_bottom_conformity(t_map *map);

#endif
