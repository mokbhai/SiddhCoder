import fizzbuzz from "../../src/fizzbuzz";

describe("Fizzbuzz", function () {
  it('For multiples of three print "Fizz" instead of the value', function () {
    expect(fizzbuzz(3)).to.equal("Fizz");
    expect(fizzbuzz(6)).to.equal("Fizz");
    expect(fizzbuzz(18)).to.equal("Fizz");
  });
  it('For multiples of five print "Buzz" instead of the value', function () {
    expect(fizzbuzz(5)).to.equal("Buzz");
    expect(fizzbuzz(10)).to.equal("Buzz");
    expect(fizzbuzz(20)).to.equal("Buzz");
  });
  it('For multiples of three and five print "FizzBuzz" instead of the value', function () {
    expect(fizzbuzz(15)).to.equal("FizzBuzz");
    expect(fizzbuzz(30)).to.equal("FizzBuzz");
    expect(fizzbuzz(45)).to.equal("FizzBuzz");
  });
});
