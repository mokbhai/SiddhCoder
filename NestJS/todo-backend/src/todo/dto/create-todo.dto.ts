import { ApiProperty } from '@nestjs/swagger';
import {
  IsString,
  IsNotEmpty,
  IsOptional,
  MinLength,
  MaxLength,
} from 'class-validator';

export class CreateTodoDto {
  @ApiProperty({
    description: 'The title of the todo',
    example: 'Complete project documentation',
    minLength: 3,
    maxLength: 100,
  })
  @IsString()
  @IsNotEmpty()
  @MinLength(3)
  @MaxLength(100)
  title: string;

  @ApiProperty({
    description: 'The description of the todo',
    example:
      'Write comprehensive documentation for the project including setup instructions and API endpoints',
    required: false,
    maxLength: 500,
  })
  @IsString()
  @IsOptional()
  @MaxLength(500)
  description?: string;
}
