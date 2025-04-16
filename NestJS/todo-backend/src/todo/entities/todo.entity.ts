import {
  Entity,
  Column,
  PrimaryGeneratedColumn,
  CreateDateColumn,
  UpdateDateColumn,
} from 'typeorm';
import { ApiProperty } from '@nestjs/swagger';

@Entity()
export class Todo {
  @ApiProperty({ description: 'The unique identifier of the todo' })
  @PrimaryGeneratedColumn()
  id: number;

  @ApiProperty({ description: 'The title of the todo' })
  @Column()
  title: string;

  @ApiProperty({ description: 'The description of the todo' })
  @Column({ nullable: true })
  description: string;

  @ApiProperty({ description: 'Whether the todo is completed' })
  @Column({ default: false })
  isCompleted: boolean;

  @ApiProperty({ description: 'The date when the todo was created' })
  @CreateDateColumn()
  createdAt: Date;

  @ApiProperty({ description: 'The date when the todo was last updated' })
  @UpdateDateColumn()
  updatedAt: Date;
}
