// primeNumber.controller.ts

import {
  Controller,
  Get,
  Param,
  HttpException,
  HttpStatus,
} from '@nestjs/common';
import { PrimeService } from './prime.service';

@Controller('isPrime')
export class PrimeController {
  constructor(private readonly primeService: PrimeService) {}

  @Get(':number')
  checkPrime(@Param('number') number: string): boolean {
    const num = parseInt(number);
    if (isNaN(num) || num <= 0) {
      throw new HttpException(
        'Invalid number provided',
        HttpStatus.BAD_REQUEST,
      );
    }
    return this.primeService.isPrime(num);
  }
}
