import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { Todo } from './entities/todo';

@Module({
  imports: [TypeOrmModule.forFeature([Todo])],
  providers: [],
  controllers: [],
})
export class TodoModule {}
