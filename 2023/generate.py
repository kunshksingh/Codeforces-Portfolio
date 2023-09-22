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
    print("Usage:")
    print('\n')
    print_usage_default()
    print('\n')
    print_usage_c()
    print('\n')
    print_usage_n()
    print('\n')
    print_usage_r()
    print('\n')
    print_usage_k()
    print('\n')
    print_usage_l()
    print('\n')
    print_usage_dl()
    print('\n')
    print_usage_t()
    print('\n')
    print_usage_dt()
    print('\n')
    print_usage_o()
    print("\nFlags can be combined and used in any order.")
    print('\n')

 
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
    print("  example: mousegen -t template.py")

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
def name_problem(letter, problem_name=None, contest_num=None, div=None):
    # Check if renaming a problem within a contest
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
    os.chdir(folder_name)

    solution_file_name = "solution" + current_language

    # Create the solution file
    with open(solution_file_name, "w") as _:
        pass
    if use_template:
        with open(template_path, "r") as template:
            with open(solution_file_name, "w") as solution:
                solution.write(template.read())

def main():
    if "-h" in sys.argv:
        if len(sys.argv) > 2:
            switch = sys.argv[2]
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
        if idx + 1 >= len(sys.argv) or sys.argv[idx + 1].startswith('-'):
            print_usage_l()
            sys.exit(1)
        current_language = args.pop(idx + 1)
        args.pop(idx)

    if "-dl" in args:
        idx = args.index("-dl")
        if idx + 1 >= len(sys.argv) or sys.argv[idx + 1].startswith('-'):
            print_usage_dl()
            sys.exit(1)
        new_default_language = args.pop(idx + 1)
        conf["DEFAULT_LANGUAGE"] = new_default_language
        with open('config.json', 'w') as file:
            json.dump(conf, file, indent=4)
        args.pop(idx)
    # Check for -dt flag
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

    # Check for -t flag
    if "-t" in args:
        idx = args.index("-t")
        if idx + 1 < len(args) and not args[idx + 1].startswith("-"):
            template_path = args.pop(idx + 1)
            use_template = True
        else:
            print_usage_t()
            sys.exit(1)
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
        # Ex. mousegen -o 123 A would open google the query "codeforces 123A", and access the first result
        idx = args.index("-o")
        if idx + 1 >= len(sys.argv) and not sys.argv[idx + 1].startswith('-'):
            print_usage_o()
            sys.exit(1)
        contest_num = args[idx + 1]
        letter = args[idx + 2] if idx + 2 < len(args) and not args[idx + 2].startswith("-") else None

        if letter:
            query = f"codeforces {contest_num}{letter}"
        else:
            query = f"codeforces {contest_num}"
        
        #Search AND access the first result on google
        import webbrowser
        from googlesearch import search
        for j in search(query, tld="co.in", num=1, stop=1, pause=2):
            webbrowser.open(j)
        

        return



    if "-n" in args:
        idx = args.index("-n")
      
        # Check if next argument after -n is a digit (contest number)

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
        if len(args) < 3:
            print_usage_default()
            sys.exit(1)
        contest_identifier, problem_name, rating = args[:3]
        handle_regular_problem(contest_identifier, problem_name, rating, current_language, use_template, template_path)


   

if __name__ == "__main__":
    main()