import {
  Controller,
  Get,
  Post,
  Body,
  Patch,
  Param,
  Delete,
  HttpStatus,
} from '@nestjs/common';
import { TodoService } from './todo.service';
import { CreateTodoDto } from './dto/create-todo.dto';
import { UpdateTodoDto } from './dto/update-todo.dto';
import {
  ApiTags,
  ApiOperation,
  ApiResponse,
  ApiParam,
  ApiBody,
} from '@nestjs/swagger';
import { Todo } from './entities/todo.entity';

@ApiTags('todos')
@Controller('todos')
export class TodoController {
  constructor(private readonly todoService: TodoService) {}

  @Post()
  @ApiOperation({
    summary: 'Create a new todo',
    description: 'Creates a new todo item with the provided details',
  })
  @ApiBody({ type: CreateTodoDto })
  @ApiResponse({
    status: HttpStatus.CREATED,
    description: 'The todo has been successfully created.',
    type: Todo,
  })
  @ApiResponse({
    status: HttpStatus.BAD_REQUEST,
    description: 'Invalid input data.',
  })
  create(@Body() createTodoDto: CreateTodoDto) {
    return this.todoService.create(createTodoDto);
  }

  @Get()
  @ApiOperation({
    summary: 'Get all todos',
    description: 'Retrieves a list of all todo items',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    description: 'Returns all todos.',
    type: [Todo],
  })
  findAll() {
    return this.todoService.findAll();
  }

  @Get(':id')
  @ApiOperation({
    summary: 'Get a todo by id',
    description: 'Retrieves a specific todo item by its ID',
  })
  @ApiParam({
    name: 'id',
    description: 'The ID of the todo to retrieve',
    type: 'number',
    example: 1,
  })
  @ApiResponse({
    status: HttpStatus.OK,
    description: 'Returns the todo.',
    type: Todo,
  })
  @ApiResponse({
    status: HttpStatus.NOT_FOUND,
    description: 'Todo not found.',
  })
  findOne(@Param('id') id: string) {
    return this.todoService.findOne(+id);
  }

  @Patch(':id')
  @ApiOperation({
    summary: 'Update a todo',
    description: 'Updates a specific todo item with the provided data',
  })
  @ApiParam({
    name: 'id',
    description: 'The ID of the todo to update',
    type: 'number',
    example: 1,
  })
  @ApiBody({ type: UpdateTodoDto })
  @ApiResponse({
    status: HttpStatus.OK,
    description: 'The todo has been successfully updated.',
    type: Todo,
  })
  @ApiResponse({
    status: HttpStatus.NOT_FOUND,
    description: 'Todo not found.',
  })
  @ApiResponse({
    status: HttpStatus.BAD_REQUEST,
    description: 'Invalid input data.',
  })
  update(@Param('id') id: string, @Body() updateTodoDto: UpdateTodoDto) {
    return this.todoService.update(+id, updateTodoDto);
  }

  @Delete(':id')
  @ApiOperation({
    summary: 'Delete a todo',
    description: 'Deletes a specific todo item by its ID',
  })
  @ApiParam({
    name: 'id',
    description: 'The ID of the todo to delete',
    type: 'number',
    example: 1,
  })
  @ApiResponse({
    status: HttpStatus.OK,
    description: 'The todo has been successfully deleted.',
  })
  @ApiResponse({
    status: HttpStatus.NOT_FOUND,
    description: 'Todo not found.',
  })
  remove(@Param('id') id: string) {
    return this.todoService.remove(+id);
  }
}
