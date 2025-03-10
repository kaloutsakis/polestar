import sys

def main(argc: int = 0, argv: list[str] = None) -> int:
    """
    The main function is the entry point of the Pythonic program.

    Parameters:
    - argc: An integer representing the number of command line arguments passed to the program.
    - argv: An array of strings representing the command line arguments passed to the program.

    Returns:
    None
    """
    print("Hello from Pythonic!")
    print("argc = ", argc)
    print("argv = ", argv)
        
    if argc:
        print("argc = ", argc)

    if argv:
        print("argv = ", argv)
        
    return 0

if __name__ == "__main__":
    main(len(sys.argv), sys.argv)