import os
import stat

def is_executable(file_path):
    """Check if a file is executable"""
    try:
        return os.path.isfile(file_path) and os.access(file_path, os.X_OK)
    except:
        return False

def has_no_extension(file_path):
    """Check if a file has no extension"""
    return os.path.isfile(file_path) and not os.path.splitext(file_path)[1]

def clean_c_executables(root_dir='.'):
    """
    Recursively delete C executable files, Java .class files, .exe files, and files without extensions
    (which are typically compiled C programs or output files)
    """
    deleted_files = []
    
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for filename in filenames:
            file_path = os.path.join(dirpath, filename)
            
            # Skip if it's a known source file or other important files
            if filename.endswith(('.c', '.java', '.py', '.md', '.txt', '.h', '.cpp')):
                continue
            
            # Delete .exe files (Windows executables)
            if filename.endswith('.exe'):
                try:
                    os.remove(file_path)
                    deleted_files.append(file_path)
                    print(f"Deleted: {file_path}")
                except Exception as e:
                    print(f"Error deleting {file_path}: {e}")
            
            # Delete Java .class files
            elif filename.endswith('.class'):
                try:
                    os.remove(file_path)
                    deleted_files.append(file_path)
                    print(f"Deleted: {file_path}")
                except Exception as e:
                    print(f"Error deleting {file_path}: {e}")
            
            # Check if file has no extension and is executable (likely a C executable)
            elif has_no_extension(file_path):
                try:
                    # Additional check: if it's executable or if it's in C/Jav folders
                    if is_executable(file_path) or '/C/' in file_path or '/Jav/' in file_path:
                        os.remove(file_path)
                        deleted_files.append(file_path)
                        print(f"Deleted: {file_path}")
                except Exception as e:
                    print(f"Error deleting {file_path}: {e}")
    
    return deleted_files

if __name__ == "__main__":
    print("Starting cleanup of C executables, .exe files, Java .class files, and output files...")
    print("=" * 60)
    
    # Get the current directory
    current_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Confirm before deletion
    response = input(f"This will delete all .exe, .class files and executable files without extensions in '{current_dir}' and subdirectories.\nContinue? (yes/no): ")
    
    if response.lower() in ['yes', 'y']:
        deleted = clean_c_executables(current_dir)
        print("=" * 60)
        print(f"\nCleanup complete! Deleted {len(deleted)} file(s).")
    else:
        print("Cleanup cancelled.")
