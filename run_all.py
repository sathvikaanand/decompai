import os
import sys
from subprocess import run

def process_folder(input_dir: str, output_dir: str, script_path: str):
    os.makedirs(output_dir, exist_ok=True)
    input_files = [f for f in os.listdir(input_dir) if os.path.isfile(os.path.join(input_dir, f))]

    if not input_files:
        print(f"No files found in input directory: {input_dir}")
        return

    print(f"Found {len(input_files)} files in {input_dir}. Processing...")

    for file_name in input_files:
        input_file_path = os.path.join(input_dir, file_name)
        print(f"Processing file: {input_file_path}")

        result = run(["python", script_path, input_file_path, output_dir], capture_output=True, text=True)

        if result.returncode != 0:
            print(f"Error processing {input_file_path}: {result.stderr}")
        else:
            print(f"Successfully processed {input_file_path}")

    print(f"All files processed. Outputs saved in {output_dir}")

def main():
    if len(sys.argv) != 4:
        print("Usage: python process_folder.py <input_dir> <output_dir> <script_path>")
        return

    input_dir = sys.argv[1]
    output_dir = sys.argv[2]
    script_path = sys.argv[3]

    process_folder(input_dir, output_dir, script_path)

if __name__ == "__main__":
    main()
