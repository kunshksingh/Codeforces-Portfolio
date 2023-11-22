import os
import re
import sys

def total_solved(rating=None):
    # Get all directories in the current path
    all_dirs = [d for d in os.listdir() if os.path.isdir(d)]
    
    # Filter to get only rating directories and the "Kattis/" directory
    check_dirs = [d for d in all_dirs if re.match(r"\[\d+\]", d) or d == "Kattis"]
    
    # For each directory in check_dirs, get the problem directories inside it
    problem_dirs = []
    for c_dir in check_dirs:
        problem_dirs.extend([os.path.join(c_dir, pd) for pd in os.listdir(c_dir) if os.path.isdir(os.path.join(c_dir, pd))])
    
    # If a rating is targeted
    if rating:
        problem_dirs = [pd for pd in problem_dirs if pd.startswith(f"[{rating}]")]

    # If no problem directories are found
    if not problem_dirs:
        print("No matching problem directories found!")
        return

    # Sort problem directories by creation time
    problem_dirs.sort(key=lambda x: os.path.getctime(x), reverse=True)
    
    solved_dirs = [pd for pd in problem_dirs if os.path.basename(pd).startswith("(S) ")]
    kattis_solved = [pd for pd in problem_dirs if os.path.basename(pd) == "Kattis" and os.path.basename(pd).startswith("(S) ")]
    normal_solved = [pd for pd in problem_dirs if os.path.basename(pd) != "Kattis" and os.path.basename(pd).startswith("(S) ")]
    if (rating):
        print(f"You've solved {len(solved_dirs)} problems rated {rating}!")
    else:
        print(f"You've solved {len(solved_dirs)} problems total!")
    print(f"    {len(kattis_solved)} from Kattis")
    print(f"    {len(normal_solved)} from Codeforces")

def mark_solved(unmark=False, specific_problem=None):
    # Get all directories in the current path
    all_dirs = [d for d in os.listdir() if os.path.isdir(d)]
    
    # Filter to get only rating directories and the "Kattis/" directory
    check_dirs = [d for d in all_dirs if re.match(r"\[\d+\]", d) or d == "Kattis"]
    
    # For each directory in check_dirs, get the problem directories inside it
    problem_dirs = []
    for c_dir in check_dirs:
        problem_dirs.extend([os.path.join(c_dir, pd) for pd in os.listdir(c_dir) if os.path.isdir(os.path.join(c_dir, pd))])
    
    # If a specific problem is targeted
    if specific_problem:
        problem_dirs = [pd for pd in problem_dirs if specific_problem in pd]

    # If no problem directories are found
    if not problem_dirs:
        print("No matching problem directories found!")
        return

    # Sort problem directories by creation time
    problem_dirs.sort(key=lambda x: os.path.getctime(x), reverse=True)
    
    target_dir = problem_dirs[0]
    base_name = os.path.basename(target_dir)
    
    # If unmarking
    if unmark:
        if base_name.startswith("(S) "):
            new_name = base_name[4:]
            os.rename(target_dir, os.path.join(os.path.dirname(target_dir), new_name))
            print(f"Unmarked '{target_dir}' as solved!")
        else:
            print(f"Problem '{target_dir}' is already marked as not solved!")
        return

    # If marking as solved
    if not base_name.startswith("(S) "):
        new_name = "(S) " + base_name
        os.rename(target_dir, os.path.join(os.path.dirname(target_dir), new_name))
        print(f"Marked '{target_dir}' as solved!")
    else:
        print(f"Problem '{target_dir}' is already marked as solved!")

def display_help():
    print("""Usage: script.py [options]
    
Options:
    -u                  : Unmark a problem directory as solved.
    -p <contest_id>     : Target a specific problem with the given contest identifier.
    -s [rating]         : Display the number of problems solved problems.
    -h, --help          : Display this help message.
    """)

if __name__ == "__main__":
    unmark_flag = "-u" in sys.argv
    specific_problem_flag_idx = None
    if "-p" in sys.argv:
        specific_problem_flag_idx = sys.argv.index("-p")

    if "-s" in sys.argv:
        rating = None
        if len(sys.argv) > sys.argv.index("-s") + 1:
            rating = sys.argv[sys.argv.index("-s") + 1]
        total_solved(rating=rating)
        sys.exit(0)
    
    if "-h" in sys.argv or "--help" in sys.argv:
        display_help()
        sys.exit(0)
    
    specific_problem = None
    if specific_problem_flag_idx and len(sys.argv) > specific_problem_flag_idx + 1:
        specific_problem = sys.argv[specific_problem_flag_idx + 1]
    
    mark_solved(unmark=unmark_flag, specific_problem=specific_problem)
