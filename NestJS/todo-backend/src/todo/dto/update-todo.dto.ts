import { PartialType } from '@nestjs/swagger';
import { CreateTodoDto } from './create-todo.dto';
import { IsBoolean, IsOptional } from 'class-validator';
import { ApiProperty } from '@nestjs/swagger';

export class UpdateTodoDto extends PartialType(CreateTodoDto) {
  @ApiProperty({
    description: 'Whether the todo is completed',
    example: true,
    required: false,
  })
  @IsBoolean()
  @IsOptional()
  isCompleted?: boolean;
}
