//
//  main.c
//  Wolfenstein
//
//  Created by Rodrigo  on 09/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include <stdio.h>
#include "library.h"

int main(int argc, char **argv)
{
	char *raw_map;
	
	raw_map = read_map();
	parse_resolution(raw_map);
	

	
	return (0);
}
