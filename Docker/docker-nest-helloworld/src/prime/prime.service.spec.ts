import { Test, TestingModule } from '@nestjs/testing';
import { PrimeService } from './prime.service';

describe('PrimeService', () => {
  let service: PrimeService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [PrimeService],
    }).compile();

    service = module.get<PrimeService>(PrimeService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });

  describe('isPrime', () => {
    it('should return true if the number is prime', () => {
      expect(service.isPrime(2)).toBe(true);
      expect(service.isPrime(3)).toBe(true);
      expect(service.isPrime(5)).toBe(true);
      expect(service.isPrime(7)).toBe(true);
      expect(service.isPrime(11)).toBe(true);
    });

    it('should return false if the number is not prime', () => {
      expect(service.isPrime(1)).toBe(false);
      expect(service.isPrime(4)).toBe(false);
      expect(service.isPrime(6)).toBe(false);
      expect(service.isPrime(8)).toBe(false);
      expect(service.isPrime(9)).toBe(false);
    });

    it('should return false if the number is less than 1', () => {
      expect(service.isPrime(-1)).toBe(false);
      expect(service.isPrime(0)).toBe(false);
    });
  });
});
