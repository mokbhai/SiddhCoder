import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { ValidationPipe } from '@nestjs/common';
import { DocumentBuilder, SwaggerModule } from '@nestjs/swagger';
import { writeFileSync } from 'fs';
import { join } from 'path';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);

  // Enable validation
  app.useGlobalPipes(new ValidationPipe());

  // Swagger documentation setup
  const config = new DocumentBuilder()
    .setTitle('Todo API')
    .setDescription('A simple Todo API with CRUD operations')
    .setVersion('1.0')
    .addTag('todos')
    .addBearerAuth()
    .build();
  const document = SwaggerModule.createDocument(app, config);

  // Save the Swagger JSON file
  const outputPath = join(process.cwd(), 'swagger-spec.json');
  writeFileSync(outputPath, JSON.stringify(document, null, 2), {
    encoding: 'utf8',
  });

  // Setup Swagger UI
  SwaggerModule.setup('api', app, document, {
    swaggerOptions: {
      persistAuthorization: true,
    },
    customSiteTitle: 'Todo API Documentation',
    customfavIcon: 'https://nestjs.com/img/favicon.png',
  });

  await app.listen(3000);
}
bootstrap();
