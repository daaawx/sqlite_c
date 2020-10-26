#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	char* buffer;
	size_t buffer_length;
	ssize_t buffer_size;
} InputBuffer;


int main(int argc, char* argv[])
{
	InputBuffer input_buffer = create_input_buffer();
	while (true)
	{
		print_promt();
		read_input(input_buffer);

		if (strcomp(input_buffer->buffer, '.exit') == 0)
		{
			close_input_buffer(input_buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Unrecognized command: '%s'\n", input_buffer->buffer);
		}
	}
}
