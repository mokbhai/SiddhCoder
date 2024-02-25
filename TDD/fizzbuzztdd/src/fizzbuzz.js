export default function fizzbuzz(value) {
  const multipleOfThree = value % 3 === 0;
  const multipleOfFive = value % 5 === 0;
  if (multipleOfThree && multipleOfFive) return "FizzBuzz";
  else if (multipleOfThree) return "Fizz";
  else if (multipleOfFive) return "Buzz";
  else return value.toString();
}
