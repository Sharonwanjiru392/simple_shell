#include "shell.h"

/**
 * _myenv - prints the current environment variables.
 * @info: Pointer to a structure containing potential arguments.
 *
 * Return: Always 0
 * This function prints the current environment variables to stdout.
 * The info parameter is unused and included only to maintain a constant
 * function prototype.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - retrieves the value of the specified environment variable
 * @info: Unused pointer to a structure containing potential arguments
 * @name: Name of the environment variable to retrieve
 *
 * Return: If the environment variable is found, return its value as a string.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initializes new environment variable or modifies existing one
 * @info: Structure containing potential arguments. Used to maintain
 * a constant function prototype
 *
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Pointer to a structure containing potential arguments.
 * Used to maintain constant function prototype.
 *
 * Description: This function removes the environment variable specified
 * by the argument passed to it.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - Populates a linked list of environment variables
 * @info: Pointer to structure containing potential arguments for the function
 *
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

