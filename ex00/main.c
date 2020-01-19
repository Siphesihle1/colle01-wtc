#include <stdlib.h>
#include <stdio.h>

void	print_str(char *str);

void	fill_puzzle(int argc, char **argv, char **puzzle)
{
	int row;
	int col;

	row = 1;
	col = 0;

	while (row < argc)
	{
		col = 0;
		while (argv[row][col] != '\0')
		{
			puzzle[row - 1][col] = argv[row][col];
			col++;		
		}
		puzzle[row - 1][col] = argv[row][col];
		row++;
	}
}

void	print_puzzle(char **puzzle)
{
	int row;
	int col;

	row = 0;
	col = 0;

	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			write(1, &puzzle[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	val_row(int index, char **puzzle)
{
	int comp;
	int j;
	int i;

	j = 0;
	while (j < 3)
	{
		i = j + 1;
		comp = puzzle[j][index];
		if (comp == '.')
		{
			j++;
			continue;
		}
		while (i < 3)
		{
			if (comp == puzzle[index][i])
				return (0);
			i++;
		}
		j++;
	}	
	return (1);
}

int	val_col(int index, char **puzzle)
{
	int comp;
	int j;
	int i;

	j = 0;
	while (j < 3)
	{
		i = j + 1;
		comp = puzzle[j][index];
		if (comp == '.')
		{
			j++;
			continue;
		}
		while (i < 3)
		{
			if (comp == puzzle[i][index])
				return (0);
			i++;
		}
		j++;
	}	
	return (1);

}

int	validate_puzzle(char **puzzle)
{
	int index;

	index = 0;
	while (index < 3)
	{
		if (!val_row(index, puzzle))
			return (0);
		index++;
	}
	index = 0;
	while (index < 3)
	{
		if (!val_col(index, puzzle))
			return (0);
		index++;
	}
	return (1);
}

int	is_valid(int next_num, char **puzzle, int row, int col)
{
	
	int i;
	
	if (puzzle[row][col] == '.') 
		return (0);
	i = 0;
	
	while (i < 3)
	{
		if (puzzle[i][col] == next_num) return (0);
 	       	if (puzzle[row][i] == next_num) return (0);
		i++;
	}
	return (1);
}

int	solve(char **puzzle, int row, int col)
{
	int next_num;
	int i;

	next_num = 1;
	if (row == 2)
		return (1);
	
	while (next_num < 4)
	{
		if (is_valid(next_num, puzzle, row, col))
		{
			puzzle[row][col] = next_num;
			if (col == 2)
			{
				if (solve(puzzle, row + 1, 0))
					return (1);
			}
			else
			{
				if (solve(puzzle, row, col + 1))
					return (1);
			}
			return (0);	
		}
		next_num++;
	}

}

int	main(int argc, char **argv)
{
	//Allocate memory for the puzzle
	char **puzzle;
	
	int index;
	
	index = 0;
	puzzle = malloc(sizeof(char *) * 3);
	while (index < 3)
	{
		puzzle[index] = malloc(sizeof(char) * 3);
		index++;
	}

	//Populate the array
	fill_puzzle(argc, argv, puzzle);		
	if (!validate_puzzle(puzzle))
	{
		print_str("Error\n");
		return (0);
	}

	if (solve(puzzle, 0, 0))
		print_puzzle(puzzle);
	else
		print_str("Error\n");
	return (0);
}


