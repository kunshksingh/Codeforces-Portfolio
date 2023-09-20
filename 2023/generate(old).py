import os
import sys
import json

def read_config():
    with open('config.json', 'r') as file:
        config = json.load(file)
        return config

def update_config(key, value):
    with open('config.json', 'r') as file:
        config = json.load(file)
    config[key] = value
    with open('config.json', 'w') as file:
        json.dump(config, file, indent=4)

conf = read_config()

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
    

def create_contest(contest_num="CURR CONTEST", div=None, extend=False):
    if div:
        contest_dir = f"{contest_num} (div {div})"
    else:
        contest_dir = contest_num

    if os.path.exists(contest_dir) and contest_num == "CURR CONTEST":
        print("Error: 'CURR CONTEST' already exists.")
        sys.exit(1)

    if not os.path.exists(contest_dir):
        os.mkdir(contest_dir)

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
            os.mkdir(letter)
            os.chdir(letter)
            with open(f"solution{DEFAULT_LANGUAGE}", "w") as _:
                pass
            with open("testcase.txt", "w") as _:
                pass
            os.chdir("..")
def name_problem(letter, problem_name=None, contest_num=None, div=None):
    if contest_num and not div:
        print("Error: Division is required when providing a contest number.")
        sys.exit(1)

    if contest_num:
        # Rename "CURR CONTEST" to the provided contest number and div
        if os.path.exists("CURR CONTEST"):
            os.rename("CURR CONTEST", f"{contest_num} (div {div})")
        else:
            print("Error: 'CURR CONTEST' not found.")
            sys.exit(1)
        return

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
    else:
        problem_dir = f"{latest_contest}{letter} - {problem_name}"
        os.rename(os.path.join(latest_contest, letter), os.path.join(latest_contest, problem_dir))

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

    if "-t" in args or "-dt" in args:
        flag = "-t" if "-t" in args else "-dt"
        idx = args.index(flag)
        if idx + 1 < len(args) and not args[idx + 1].startswith("-"):
            template_path = args.pop(idx + 1)
        else:
            template_path = DEFAULT_TEMPLATE_PATH
        use_template = True
        if flag == "-dt":
            conf["DEFAULT_TEMPLATE_PATH"] = template_path
            DEFAULT_TEMPLATE_PATH = template_path
            if default_template and template_path != DEFAULT_TEMPLATE_PATH:
                with open(template_path, 'r') as new_template_file:
                    with open(DEFAULT_TEMPLATE_PATH, 'w') as default_template_file:
                        default_template_file.write(new_template_file.read())

        args.pop(idx)

    if "-c" in args:
        idx = args.index("-c")
        if idx + 1 >= len(sys.argv) or sys.argv[idx + 1].startswith('-'):
            print_usage_c()
            sys.exit(1)
        extend = "-e" in args
        if extend:
            args.remove("-e")
        contest_num = args[idx + 1] if idx + 1 < len(args) and not args[idx + 1].startswith("-") else "CURR CONTEST"
        div = args[idx + 2] if idx + 2 < len(args) and not args[idx + 2].startswith("-") else None
        create_contest(contest_num, div, extend)
        return

    if "-n" in args:
        idx = args.index("-n")
        if idx + 1 >= len(sys.argv) or sys.argv[idx + 1].startswith('-'):
            print_usage_n()
            sys.exit(1)
        letter = args[idx + 1] if idx + 1 < len(args) and not args[idx + 1].startswith("-") else None
        problem_name = args[idx + 2] if idx + 2 < len(args) and not args[idx + 2].startswith("-") else None
        if not problem_name:
            contest_num = args[idx + 2]
            div = args[idx + 3]
            name_problem(letter, None, contest_num, div)
        else:
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
