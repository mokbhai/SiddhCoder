// primeNumber.controller.spec.ts

import { Test, TestingModule } from '@nestjs/testing';
import { PrimeController } from './prime.controller';
import { PrimeService } from './prime.service';
import { HttpException, HttpStatus } from '@nestjs/common';

describe('PrimeNumberController', () => {
  let controller: PrimeController;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      controllers: [PrimeController],
      providers: [PrimeService],
    }).compile();

    controller = module.get<PrimeController>(PrimeController);
  });

  it('should be defined', () => {
    expect(controller).toBeDefined();
  });

  describe('checkPrime', () => {
    it('should throw 400 error if invalid number provided', () => {
      const invalidNumber = 'abc';
      expect(() => controller.checkPrime(invalidNumber)).toThrow(HttpException);
      expect(() => controller.checkPrime(invalidNumber)).toThrow(
        new HttpException('Invalid number provided', HttpStatus.BAD_REQUEST),
      );
    });

    it('should return true for prime numbers', () => {
      // Test prime number functionality as desired
    });

    it('should return false for non-prime numbers', () => {
      // Test non-prime number functionality as desired
    });
  });
});
