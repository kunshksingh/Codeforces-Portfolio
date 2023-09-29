import os
import sys
import json

DEFAULT_CONFIG_PATH = 'config.json'

# Read the configuration
def read_config():
    if not os.path.exists(DEFAULT_CONFIG_PATH):
        return {"DEFAULT_LANGUAGE": ".py", "DEFAULT_TEMPLATE_PATH": "template.py"}
    with open(DEFAULT_CONFIG_PATH, 'r') as file:
        return json.load(file)
    
def save_config():
    with open(DEFAULT_CONFIG_PATH, 'w') as file:
        json.dump(conf, file)

def update_config(key, value):
    with open('config.json', 'r') as file:
        config = json.load(file)

    config[key] = value
    with open('config.json', 'w') as file:
        json.dump(config, file, indent=4)

conf = read_config()
DEFAULT_LANGUAGE_PATH = conf.get("DEFAULT_LANGUAGE", ".py")
DEFAULT_TEMPLATE_PATH = conf.get("DEFAULT_TEMPLATE_PATH", "template.py")

DEFAULT_LANGUAGE = conf.get("DEFAULT_LANGUAGE", ".py")
DEFAULT_TEMPLATE_PATH =  conf.get("DEFAULT_TEMPLATE_PATH", "./template.py")

def print_usage():
    print("""Usage: mousegen [options]
Default:
    mousegen <contest_identifier> <problem_name> <rating>
    example: mousegen 123A \"Free Food\" 1500
    Important: Include quotes around the problem name always.
          
Options:
    -c [contest_number div] [-e]         : Create a contest directory.
    -n [letter problem_name]             : Name a problem (within a contest).
    -r rating -n [letter problem_name]   : Rate a problem (within a contest).
    -r rating -n [contest_number div]    : Rate a problem (within a contest).
    -k [letter problem_name month day]   : Create a Kattis problem directory.
    -l .extension                        : Set the default language.
    -dl .extension                       : Set the default language permanently.
    -t <template_path>                   : Use a template for the solution file.
    -dt <template_path>                  : Set the default template permanently.
    -o <contest_number> <problem_letter> : Open Codeforces link.
    -h, --help                           : Display this help message.
    """)
    

 
def print_usage_default():
    print("\nDefault usage (no flags):")
    print("  mousegen <contest_identifier> <problem_name> <rating>")
    print("  example: mousegen 123A \"Free Food\" 1500")

def print_usage_c():
    print("Usage for -c flag (Contests):")
    print("  mousegen -c [contest_number div] [-e]")
    print("    -e: Extend the contest by adding the next problem.")
    print("  example: mousegen -c 123 2")

def print_usage_n():
    print("Usage for -n flag (Naming):")
    print("  mousegen -n [letter problem_name]")
    print("  example: mousegen -n A - \"Free Food\" OR mousegen -n 123 2")

def print_usage_r():
    print("Usage for -r flag (Rating):")
    print("  mousegen -r rating -n [letter problem_name] OR mousegen -r rating -n [contest_number div]")
    print("  example: mousegen -r 1500 -n A - \"Free Food\" OR mousegen -r 1500 -n 123 2")

def print_usage_k():
    print("Usage for -k flag (Kattis problems):")
    print("  mousegen -k letter problem_name month day")

def print_usage_l():
    print("Usage for -l flag (Language of solution):")
    print("  mousegen -l .extension")
    print("  example: mousegen -l .py")

def print_usage_dl():
    print("Usage for -dl flag (Default language):")
    print("  mousegen -dl <.extension>")
    print("  example: mousegen -dl .py")

def print_usage_t():
    print("Usage for -t flag (Specify a template):")
    print("  mousegen -t <template_path>")
    print("  example: mousegen 123A \"Free Food\" 1500 -t template.py")

def print_usage_dt():
    print("Usage for -dt flag (Default template):")
    print("  mousegen -dt <template_path>")
    print("  example: mousegen -dt template.py")

def print_usage_o():
    print("Usage for -o flag (Open Codeforces link):")
    print("  mousegen -o <contest_number> <problem_letter>")
    print("  example: mousegen -o 123 A")

# Create a contest
def create_contest(contest_num="CURR CONTEST", div=None, extend=False):
    rating_dir = "Uncategorized"
    if not os.path.exists(rating_dir):
        os.mkdir(rating_dir)
    os.chdir(rating_dir)

    if div:
        contest_dir = f"{contest_num} (div {div})"
    else:
        contest_dir = contest_num

    if os.path.exists(contest_dir) and contest_num == "CURR CONTEST":
        print("Error: 'CURR CONTEST' already exists.")
        sys.exit(1)

    if not os.path.exists(contest_dir):
        os.makedirs(contest_dir)

    os.chdir(contest_dir)

    # If extending, find the next letter
    if extend:
        existing_dirs = sorted([d for d in os.listdir() if os.path.isdir(d)])
        next_letter = chr(ord(existing_dirs[-1]) + 1) if existing_dirs else 'A'
        problem_dirs = [next_letter]
    else:
        problem_dirs = ['A', 'B', 'C', 'D', 'E', 'F']

    for letter in problem_dirs:
        if not os.path.exists(letter):
            os.makedirs(letter)
            os.chdir(letter)
            with open(f"solution{DEFAULT_LANGUAGE_PATH}", "w") as _:
                pass
            with open("testcase.txt", "w") as _:
                pass
            os.chdir("..")

# Name a problem
def name_problem(letter, problem_name=None, contest_num=None, div=None, reset=False):
    # Make sure that there is at least one argument
    if not letter and not contest_num and not div and not problem_name:
        print_usage_n()
        sys.exit(1)
    # TODO: Make sure current directory is Uncategorized
    # if not os.path.exists("Uncategorized") and os.path.isdir("Uncategorized"):
    #     sys.exit(1)
    # elif os.path.exists("Uncategorized"):
    #     os.chdir("Uncategorized")

    if reset:
        if not letter:
            print("Error: Letter must be specified.")
            sys.exit(1)
        contest_dirs = sorted([d for d in os.listdir() if os.path.isdir(d)])
        latest_contest = contest_dirs[-1]
        problem_dir = f"{letter} - "
        matching_dirs = [d for d in os.listdir(latest_contest) if d.startswith(problem_dir)]
        if not matching_dirs:
            print(f"Error: Problem {letter} in contest {latest_contest} either does not have a valid format or is already reset.")
            sys.exit(1)
        problem_dir = matching_dirs[0]
        os.rename(os.path.join(latest_contest, problem_dir), os.path.join(latest_contest, f"{letter}"))
        return

    if letter and problem_name:
        # Find the latest contest directory
        contest_dirs = sorted([d for d in os.listdir() if os.path.isdir(d)])
        latest_contest = contest_dirs[-1]
        if not problem_name:
            # Expect the problem to have a format like "123A - Problem Name"
            problem_dir = f"{latest_contest}{letter} - "
            matching_dirs = [d for d in os.listdir(latest_contest) if d.startswith(problem_dir)]
            if not matching_dirs:
                print(f"Error: Problem {letter} in contest {latest_contest} does not have a valid format.")
                sys.exit(1)
            problem_dir = matching_dirs[0]
        else:
            old_dir = os.path.join(latest_contest, letter)
            new_dir = os.path.join(latest_contest, f"{letter} - {problem_name}")
            # If we find the letter in our path
            if os.path.exists(old_dir) or letter in os.listdir(latest_contest):
                # Make sure our old_dir is a valid directory that contains the letter
                if not os.path.exists(old_dir):
                    old_dir = os.path.join(latest_contest, [d for d in os.listdir(latest_contest) if d.startswith(letter)][0])
                os.rename(old_dir, new_dir)
            else:
                if not os.path.exists(old_dir):
                    old_dir = os.path.join(latest_contest, [d for d in os.listdir(latest_contest) if d.startswith(letter)][0])
                if os.path.exists(old_dir):
                    os.rename(old_dir, new_dir)
                else:
                    print(f"Error: Directory {old_dir} does not exist.")
                    sys.exit(1)

    # Check if renaming a contest
    elif contest_num and div:
        if os.path.exists("CURR CONTEST"):
            os.rename("CURR CONTEST", f"{contest_num} (div {div})")
        else:
            print("Error: 'CURR CONTEST' not found.")
            sys.exit(1)
        return

    else:
        print("Error: Insufficient information provided to name the problem or contest.")
        sys.exit(1)

    # The rest of the functions...
def rate_problem(rating, letter, problem_name=None):
    # Find the latest contest directory
    contest_dirs = sorted([d for d in os.listdir() if os.path.isdir(d)])
    latest_contest = contest_dirs[-1]

    if not problem_name:
        # Expect the problem to have a format like "123A - Problem Name"
        problem_dir = f"{latest_contest}{letter} - "
        matching_dirs = [d for d in os.listdir(latest_contest) if d.startswith(problem_dir)]
        if not matching_dirs:
            print(f"Error: Problem {letter} in contest {latest_contest} does not have a valid format.")
            sys.exit(1)
        problem_dir = matching_dirs[0]
    else:
        problem_dir = f"{latest_contest}{letter} - {problem_name}"

    rating_dir = f"[{rating}]"
    if not os.path.exists(rating_dir):
        os.mkdir(rating_dir)

    # Move the problem to the rating directory and rename it
    os.rename(os.path.join(latest_contest, problem_dir), os.path.join(rating_dir, problem_dir))

def handle_kattis_problem(letter, problem_name, month, day, current_language, use_template, template_path):
    # Enter the Kattis directory based on the date
    date_dir = f"{month} {day}"
    kattis_dir = os.path.join("Kattis", date_dir)
    if not os.path.exists(kattis_dir):
        os.makedirs(kattis_dir)
    os.chdir(kattis_dir)

    # Use the letter and problem name to create a folder
    folder_name = f"{letter} - {problem_name}"
    if not os.path.exists(folder_name):
        os.mkdir(folder_name)
    os.chdir(folder_name)

    solution_file_name = f"{letter}{current_language}"

    # Create the solution file
    with open(solution_file_name, "w") as _:
        pass
    if use_template:
        with open(template_path, "r") as template:
            print(template.read())
            with open(solution_file_name, "w") as solution:
                solution.write(template.read())
    
    # Create the testcase file
    with open("testcase.txt", "w") as _:
        pass

def handle_regular_problem(contest_identifier, problem_name, rating, current_language, use_template, template_path):
    # Enter the directory based on rating
    rating_dir = f"[{rating}]"
    if not os.path.exists(rating_dir):
        os.mkdir(rating_dir)
    os.chdir(rating_dir)

    # Use the contest identifier and problem name to create a folder
    folder_name = f"{contest_identifier} - {problem_name}"
    if not os.path.exists(folder_name):
        os.mkdir(folder_name)
    else:
        print("Error: Problem already exists.")
        sys.exit(1)
    os.chdir(folder_name)

    solution_file_name = "solution" + current_language

    # Create the solution file
    with open(solution_file_name, "w") as _:
        pass
    if use_template:
        with open(template_path, "r") as template:
            with open(solution_file_name, "w") as solution:
                solution.write(template.read())
    
    # Create the testcase file
    with open("testcase.txt", "w") as _:
        pass
def enter_directory(directory):
    if not os.path.exists(directory):
        print(f"Error: Directory {directory} does not exist.")
        sys.exit(1)
    os.chdir(directory)



def main():
    if "-h" in sys.argv:
        if len(sys.argv) >= 2:
            switch = sys.argv[1]
            if len(sys.argv) >= 3:
                # Print usage of the leftmost non -h flag
                for i in range(1, len(sys.argv)):
                    if sys.argv[i] == "-h":
                        continue
                    else:
                        switch = sys.argv[i]
                        break
               


            if switch == "-c":
                print_usage_c()
            elif switch == "-n":
                print_usage_n()
            elif switch == "-r":
                print_usage_r()
            elif switch == "-k":
                print_usage_k()
            elif switch == "-l":
                print_usage_l()
            elif switch == "-dl":
                print_usage_dl()
            elif switch == "-t":
                print_usage_t()
            elif switch == "-dt":
                print_usage_dt()
            elif switch == "-o":
                print_usage_o()
            elif switch == "--all" or switch == "-a":
                print_usage()
            else:
                print_usage()

        else:
            print_usage()
        sys.exit(0)
    # Initial setup
    global DEFAULT_TEMPLATE_PATH
    global DEFAULT_LANGUAGE
    global conf
    
    default_template = False
    default_language = False
    new_default_language = DEFAULT_LANGUAGE 

    current_language = DEFAULT_LANGUAGE
    use_template = False
    template_path = DEFAULT_TEMPLATE_PATH

    # Parse flags
    args = sys.argv[1:]

    if "-l" in args:
        idx = args.index("-l")
        if idx + 1 >= len(args) or args[idx + 1].startswith('-'):
            print_usage_l()
            sys.exit(1)
        current_language = args.pop(idx + 1)
        args.pop(idx)

    if "-dl" in args:
        idx = args.index("-dl")
        if idx + 1 >= len(args) or args[idx + 1].startswith('-'):
            print_usage_dl()
            sys.exit(1)
        new_default_language = args.pop(idx + 1)
        conf["DEFAULT_LANGUAGE"] = new_default_language
        with open('config.json', 'w') as file:
            json.dump(conf, file, indent=4)
        args.pop(idx)

    if "-dt" in args:
        idx = args.index("-dt")
        if idx + 1 < len(args) and not args[idx + 1].startswith("-"):
            template_path = args.pop(idx + 1)
        else:
            print_usage_dt()
            sys.exit(1)
        conf["DEFAULT_TEMPLATE_PATH"] = template_path
        save_config()
        args.pop(idx)


    if "-t" in args:
        idx = args.index("-t")
        if idx + 1 < len(args) and not args[idx + 1].startswith("-"):
            template_path = args.pop(idx + 1)
            if template_path.startswith("./"):
                template_path = template_path[2:]
                template_path = os.path.join(os.getcwd(), template_path)
            if not os.path.exists(template_path):
                print(f"Error: Template {template_path} does not exist.")
                sys.exit(1)
            use_template = True
        else:
            # Check if we have a default template and make sure it isn't empty
            if not DEFAULT_TEMPLATE_PATH and not os.path.exists(DEFAULT_TEMPLATE_PATH) and os.path.getsize(DEFAULT_TEMPLATE_PATH) >= 0:
                print("Error: No default template found.")
                print_usage_dt()
                print_usage_t()
                sys.exit(1)
            template_path = DEFAULT_TEMPLATE_PATH
        args.pop(idx)

    if "-c" in args:
        idx = args.index("-c")
        extend = "-e" in args
        if extend:
            args.remove("-e")
        
        contest_num = "CURR CONTEST"
        div = None

        if idx + 1 < len(args) and not args[idx + 1].startswith("-"):
            contest_num = args.pop(idx + 1)
            if idx + 1 < len(args) and not args[idx + 1].startswith("-"):
                div = args.pop(idx + 1)

        create_contest(contest_num, div, extend)
        return
    
    if "-o" in args:
        # Opens codeforces link to a problem
        # Ex1. mousegen -o "Problem Name" would open google the query "codeforces Problem Name", and access the first result
        # Ex2. mousegen -o 123 A would open the link https://codeforces.com/problemset/problem/123/A
        idx = args.index("-o")
        if idx + 1 >= len(sys.argv) and not sys.argv[idx + 1].startswith('-'):
            print_usage_o()
            sys.exit(1)
            
        if idx + 1 < len(args) and args[idx + 1].isdigit():
            contest_num = args[idx + 1]
            letter = args[idx + 2] if idx + 2 < len(args) and not args[idx + 2].startswith("-") else None
        else:
            problem_name = args[idx + 1] if idx + 2 < len(args) and not args[idx + 2].startswith("-") else None

        
        if letter:
            os.system(f"open https://codeforces.com/problemset/problem/{contest_num}/{letter}")
        elif problem_name:
            os.system(f"open https://www.google.com/search?q=codeforces+{problem_name}")
        return



    if "-n" in args:
        idx = args.index("-n")
      
        # Check if next argument after -n is a digit (contest number)
        if "--reset" in args:
            letter = args[idx + 1] if idx + 1 < len(args) and not args[idx + 1].startswith("-") else None
            idx = args.index("--reset")
            args.pop(idx)
            name_problem(letter, reset=True)
            return
        if idx + 1 < len(args) and args[idx + 1].isdigit():
            contest_num = args[idx + 1]
            os.chdir("Uncategorized")
            if contest_num == "CURR CONTEST" and not os.path.exists("CURR CONTEST"):
                print("Error: 'CURR CONTEST' not found.")
                sys.exit(1)
            div = args[idx + 2] if idx + 2 < len(args) else None
            name_problem(None, None, contest_num, div)
        else:
            letter = args[idx + 1] if idx + 1 < len(args) and not args[idx + 1].startswith("-") else None
            problem_name = args[idx + 2] if idx + 2 < len(args) and not args[idx + 2].startswith("-") else None
            name_problem(letter, problem_name)
        return

    if "-r" in args and "-n" in args:
        idx = args.index("-r")
        if idx + 1 >= len(sys.argv) or sys.argv[idx + 1].startswith('-'):
            print_usage_r()
            sys.exit(1)
        rating = args[idx + 1]
        letter = args[idx + 2] if idx + 2 < len(args) and not args[idx + 2].startswith("-") else None
        problem_name = args[idx + 3] if idx + 3 < len(args) and not args[idx + 3].startswith("-") else None
        rate_problem(rating, letter, problem_name)
        return

    # Handling Kattis and regular problems
    is_kattis = "-k" in args
  
    if is_kattis:
        idx = args.index("-k")
        if idx + 1 >= len(sys.argv) or sys.argv[idx + 1].startswith('-'):
            print_usage_k()
            sys.exit(1)
        letter, problem_name, month, day = args[1:5]
        handle_kattis_problem(letter, problem_name, month, day, current_language, use_template, template_path)
    else:
        if len(args) < 3 or len(args) > 4:
            print_usage_default()
            sys.exit(1)
        contest_identifier, problem_name, rating = args[:3]
        if not rating.isdigit() and len(args) == 3:
            print("Error: Rating must be a number.")
            sys.exit(1)
        elif not rating.isdigit():
            print_usage_default()
            sys.exit(1)
        handle_regular_problem(contest_identifier, problem_name, rating, current_language, use_template, template_path)

   

if __name__ == "__main__":
    main()
