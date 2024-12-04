import re

# Base class for the solution
class SolutionBase:
    def part1(self, data):
        raise NotImplementedError

    def part2(self, data):
        raise NotImplementedError

# Solution class inheriting from SolutionBase
class Solution(SolutionBase):
    def part1(self, data):
        # Pattern to match mul(num1, num2)
        pattern = r"mul\((\d{1,3}),(\d{1,3})\)"
        matches = re.findall(pattern, "".join(data))

        # Sum of products of matched numbers
        result = sum(int(x) * int(y) for x, y in matches)

        return result

    def part2(self, data):
        # Pattern to match mul(num1, num2), do(), or don't()
        pattern = r"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))"
        instructions = re.findall(pattern, "".join(data))

        enabled = True
        result = 0

        # Process each instruction
        for inst in instructions:
            match inst[0]:
                case "do()":
                    enabled = True
                case "don't()":
                    enabled = False
                case _ if enabled:
                    result += int(inst[1]) * int(inst[2])

        return result

# Main function
def main():
    # File path for input data
    file_path = "inp_Day3.txt"

    # Read data from the file
    try:
        with open(file_path, "r") as file:
            data = file.readlines()

        # Create an instance of Solution
        solution = Solution()

        # Solve part1 and part2
        result1 = solution.part1(data)
        result2 = solution.part2(data)

        # Display results
        print(f"Part 1 Result: {result1}")
        print(f"Part 2 Result: {result2}")
    except FileNotFoundError:
        print(f"Error: The file '{file_path}' was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
